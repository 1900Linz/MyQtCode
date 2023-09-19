////开启UTF-8支持
/// qmake: CONFIG += utf8_source
/// QMAKE_CXXFLAGS += /utf-8
/// MSVC: /utf-8
/// GCC&Clang: -finput-charser=UTF-8 -fexec-charset=UTF-8
///
////如果在MSVC中使用预编译头文件,在预编译头stdafx.h文件加入
//#if defined(_MSC_VER) && (_MSC_VER >= 1600)
//# pragma execution_character_set("utf-8")
//#endif
////Visual Studio可以下载插件ForceUTF8 (with BOM)
///所有源文件和头文件都会保存为“UTF-8+BOM”编码
////main函数入口设置中文编码
//int main(){
//#include <QTextCodec>
//    QApplication a(argc, argv);
//    //设置中文字体
//    a.setFont(QFont("Microsoft Yahei", 9));
////设置中文编码
//#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
//#if _MSC_VER
//    QTextCodec *codec = QTextCodec::codecForName("gbk");
//#else
//    QTextCodec *codec = QTextCodec::codecForName("utf-8");
//#endif
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForTr(codec);
//#else
//    QTextCodec *codec = QTextCodec::codecForName("utf-8");
//    QTextCodec::setCodecForLocale(codec);
//#endif
//}
