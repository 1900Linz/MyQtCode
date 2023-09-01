#include "filedialogdelegate.h"
#include <QCoreApplication>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>

FileDialogDelegate::FileDialogDelegate(QObject *parent)
    : QObject(parent)
    , dialog(new QFileDialog)
{
    dialog->setWindowTitle(QCoreApplication::applicationName());
    connect(this, &FileDialogDelegate::signPreOpen, this, &FileDialogDelegate::openDialog, Qt::QueuedConnection);
    connect(this, &FileDialogDelegate::signPreClose, this, [=](){
        dialog->reject();
    }, Qt::QueuedConnection);
}

void FileDialogDelegate::initSetting(const QString &filepath, const QSettings::Format &format)
{
    iniPath = filepath;
    iniFormat = format;
}

void FileDialogDelegate::open()
{
    emit signPreOpen();
}

void FileDialogDelegate::close()
{
    emit signPreClose();
}

void FileDialogDelegate::selectUrl(const QUrl &url)
{
    qDebug() << url.toString();
}

QString FileDialogDelegate::desktopPath()
{
    return QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
}

QUrl FileDialogDelegate::desktopUrl()
{
    return QUrl::fromLocalFile(desktopPath());
}

void FileDialogDelegate::setMode(const int & mode)
{
    if (mode != dialogMode) {
        dialogMode = mode;
        emit modeChanged();
    }
}

void FileDialogDelegate::setCurrentFiles(const QList<QUrl> &url)
{
    if (url != currentFiles) {
        currentFiles = url;
        emit currentFilesChanged();
    }
}

void FileDialogDelegate::setCurrentFile(const QUrl &urls)
{
    auto currenturl = currentFiles[0];
    if (urls != currenturl) {
        currenturl = urls;
        emit currentFilesChanged();
    }
}

void FileDialogDelegate::openDialog()
{
    switch (dialogMode) {
    case ByFile:
        dialog->setFileMode(QFileDialog::ExistingFile);
        break;
    case ByFiles:
        dialog->setFileMode(QFileDialog::ExistingFiles);
        break;
    case ToSave:
        dialog->setFileMode(QFileDialog::AnyFile);
        dialog->setAcceptMode(QFileDialog::AcceptSave);
        break;
    default: break;
    }

    dialog->setNameFilters(iniNameFilters);
    dialog->setDirectory(getDefaultPath());

    const int ret = dialog->exec();
    if (ret == QDialog::Rejected) {
        emit rejected();
        return;
    }

    auto urls = dialog->selectedUrls();

    if (urls.isEmpty()) {
        setCurrentFile(QUrl());
        setDefaultPath(desktopPath());
    }

    setCurrentFiles(urls);

    ///
    /// \brief 记住最近一次目录
    ///
    QFileInfo info(currentFiles[0].toLocalFile());
    qDebug() << info.absoluteFilePath();


    setDefaultPath(info.absoluteFilePath());


    emit accepted();
}

QString FileDialogDelegate::getDefaultPath()
{
    //QFileDialog默认实现在构造时恢复，析构时保存

    //记录上一次选择的路径
    QSettings setting(iniPath, QSettings::IniFormat);
    QString dirpath = setting.value("LastPath").toString();
    if (dirpath.isEmpty()) {
        //默认桌面路径
        dirpath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    }
    qDebug()<<"get default"<<dirpath;
    return dirpath;
}

void FileDialogDelegate::setDefaultPath(const QString &dirpath)
{
    QSettings setting(iniPath, QSettings::IniFormat);
    setting.setValue("LastPath", dirpath);
    qDebug()<<"set default"<<dirpath;
}
