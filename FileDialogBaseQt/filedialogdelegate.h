#ifndef FILEDIALOGDELEGATE_H
#define FILEDIALOGDELEGATE_H

#include <QObject>
#include <QUrl>
#include <QSettings>
#include <QFileDialog>

///
/// \brief The FileDialogDelegate class used to provide filedialog to qmlEngine
/// \author linz1900
///
class FileDialogDelegate : public QObject
{
    Q_OBJECT
    Q_ENUMS(DialogMode);

    Q_PROPERTY(int dialogMode READ getMode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QList<QUrl> currentFiles READ getCurrentFiles NOTIFY currentFilesChanged)

public:
    enum DialogMode{
        ByFile,
        ByFiles,
        ToSave
    };

public:
    explicit FileDialogDelegate(QObject *parent = nullptr);
    ~FileDialogDelegate() {}

    static void initSetting(const QString &filepath, const QSettings::Format &format = QSettings::IniFormat);

    Q_INVOKABLE void open();
    Q_INVOKABLE void close();
    Q_INVOKABLE void selectUrl(const QUrl &url);

    //桌面路径
    Q_INVOKABLE static QString desktopPath();
    Q_INVOKABLE static QUrl desktopUrl();

    void setMode(const int&) ;
    void setCurrentFiles(const QList<QUrl> &) ;
    void setCurrentFile(const QUrl&) ;

    int getMode() const {return dialogMode;}
    QStringList getNameFilters() const {return iniNameFilters;}
    QList<QUrl> getCurrentFiles() const {return currentFiles;}
    QUrl getCurrentFile() const {return currentFiles[0];}

private:
    Q_SLOT void openDialog();

    QString getDefaultPath();
    void setDefaultPath(const QString &dirpath);

private:
    inline static QString iniPath;
    inline static QSettings::Format iniFormat{QSettings::IniFormat};
    inline static QStringList iniNameFilters{"All (*.*)"};

    int dialogMode{DialogMode::ByFile};

    QList<QUrl> currentFiles;//fileDialog use 0, and filesDialog use whole one

    QFileDialog *dialog;

signals:
    void signPreOpen();
    void signPreClose();
    void accepted();
    void rejected();

    void modeChanged();
    void titleChanged();
    void nameFiltersChanged();
    void currentUrlChanged();
    void currentFilesChanged();
};

#endif // FILEDIALOGDELEGATE_H
