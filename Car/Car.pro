QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT +=sql
QT += svg

INCLUDEPATH += D:\opencv\opencv_lib\install\include\opencv\
               D:\opencv\opencv_lib\install\include\opencv2\
               D:\opencv\opencv_lib\install\include\

LIBS +=  D:\opencv\opencv_lib\install\x64\mingw\lib\libopencv_*.dll.a

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customerclass.cpp \
    main.cpp \
    mainobject.cpp \
    maintitle.cpp \
    mainwindow.cpp \
    opaacount.cpp \
    recognitioncar.cpp \
    registerpage.cpp \
    slderimage.cpp \
    sliderwidget.cpp \
    src/core/chars_identify.cpp \
    src/core/chars_recognise.cpp \
    src/core/chars_segment.cpp \
    src/core/core_func.cpp \
    src/core/feature.cpp \
    src/core/params.cpp \
    src/core/plate_detect.cpp \
    src/core/plate_judge.cpp \
    src/core/plate_locate.cpp \
    src/core/plate_recognize.cpp \
    src/train/annCh_train.cpp \
    src/train/ann_train.cpp \
    src/train/create_data.cpp \
    src/train/svm_train.cpp \
    src/train/train.cpp \
    src/util/kv.cpp \
    src/util/program_options.cpp \
    src/util/util.cpp \
    thirdparty/LBP/helper.cpp \
    thirdparty/LBP/lbp.cpp \
    thirdparty/mser/mser2.cpp \
    thirdparty/svm/corrected_svm.cpp \
    thirdparty/textDetect/erfilter.cpp \
    thirdparty/xmlParser/xmlParser.cpp

HEADERS += \
    customerclass.h \
    easypr.h \
    easypr/api.hpp \
    easypr/config.h \
    easypr/core/character.hpp \
    easypr/core/chars_identify.h \
    easypr/core/chars_recognise.h \
    easypr/core/chars_segment.h \
    easypr/core/core_func.h \
    easypr/core/feature.h \
    easypr/core/params.h \
    easypr/core/plate.hpp \
    easypr/core/plate_detect.h \
    easypr/core/plate_judge.h \
    easypr/core/plate_locate.h \
    easypr/core/plate_recognize.h \
    easypr/train/annCh_train.h \
    easypr/train/ann_train.h \
    easypr/train/create_data.h \
    easypr/train/svm_train.h \
    easypr/train/train.h \
    easypr/util/kv.h \
    easypr/util/program_options.h \
    easypr/util/switch.hpp \
    easypr/util/util.h \
    easypr/version.h \
    mainobject.h \
    maintitle.h \
    mainwindow.h \
    opaacount.h \
    recognitioncar.h \
    registerpage.h \
    slderimage.h \
    sliderwidget.h \
    test/accuracy.hpp \
    test/chars.hpp \
    test/config.hpp \
    test/plate.hpp \
    test/result.hpp \
    thirdparty/LBP/helper.hpp \
    thirdparty/LBP/lbp.hpp \
    thirdparty/mser/mser2.hpp \
    thirdparty/svm/precomp.hpp \
    thirdparty/textDetect/erfilter.hpp \
    thirdparty/xmlParser/xmlParser.h

FORMS += \
    maintitle.ui \
    mainwindow.ui \
    opaacount.ui \
    recognitioncar.ui \
    registerpage.ui \
    slderimage.ui \
    sliderwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    model/ann.xml \
    model/annCh.xml \
    model/ann_chinese.xml \
    model/province_mapping \
    model/svm_hist.xml \
    resources/doc/res/13ver.jpg \
    resources/doc/res/arch.jpg \
    resources/doc/res/batch_operation.jpg \
    resources/doc/res/batch_result.png \
    resources/doc/res/big_1.jpg \
    resources/doc/res/bigangle.png \
    resources/doc/res/blue_chars.png \
    resources/doc/res/blue_plate.jpg \
    resources/doc/res/contrast_1.jpg \
    resources/doc/res/debug.jpg \
    resources/doc/res/extreme_test.jpg \
    resources/doc/res/fetures.png \
    resources/doc/res/gdsl.jpg \
    resources/doc/res/general_test.jpg \
    resources/doc/res/levenshtein1.jpg \
    resources/doc/res/levenshtein2.jpg \
    resources/doc/res/levenshtein3.jpg \
    resources/doc/res/levenshteinAll.JPG \
    resources/doc/res/lifemode.jpg \
    resources/doc/res/near_1.jpg \
    resources/doc/res/new50.jpg \
    resources/doc/res/night_1.jpg \
    resources/doc/res/night_2.jpg \
    resources/doc/res/normal_ostu.jpg \
    resources/doc/res/not_avg_contrast.jpg \
    resources/doc/res/one_image_detect.jpg \
    resources/doc/res/plate_detect.jpg \
    resources/doc/res/plate_locate.jpg \
    resources/doc/res/spatial_ostu.jpg \
    resources/doc/res/svm_data.jpg \
    resources/doc/res/svm_rate.jpg \
    resources/doc/res/svm_train.jpg \
    resources/doc/res/svm_upgragde.png \
    resources/doc/res/testresult.png \
    resources/doc/res/testresult_1.3alpha.png \
    resources/doc/res/testresult_1.3beta.png \
    resources/doc/res/v1.5_result.jpg \
    resources/doc/res/window.png \
    resources/doc/res/yellow_chars.png \
    resources/doc/res/yellow_plate.jpg \
    resources/doc/????????????.txt \
    resources/image/GDSL.txt \
    resources/image/chars_identify.jpg \
    resources/image/chars_recognise.jpg \
    resources/image/chars_segment.jpg \
    resources/image/general_test/GroundTruth_others.xml \
    resources/image/general_test/GroundTruth_windows.xml \
    resources/image/general_test/???A88731.jpg \
    resources/image/general_test/???CX8888.jpg \
    resources/image/general_test/???FK5358.jpg \
    resources/image/general_test/???H99999.jpg \
    resources/image/general_test/???PC5U22.jpg \
    resources/image/general_test/???FA3215.jpg \
    resources/image/general_test/???A019W2.jpg \
    resources/image/general_test/???A095Q5.jpg \
    resources/image/general_test/???A09X20.jpg \
    resources/image/general_test/???A105LR.jpg \
    resources/image/general_test/???A113YP.jpg \
    resources/image/general_test/???A561WP.jpg \
    resources/image/general_test/???A572F4.jpg \
    resources/image/general_test/???A762ZS.jpg \
    resources/image/general_test/???A82M83.jpg \
    resources/image/general_test/???A88888.jpg \
    resources/image/general_test/???AA662F.jpg \
    resources/image/general_test/???AE8H60.jpg \
    resources/image/general_test/???AEK882.jpg \
    resources/image/general_test/???AGU052.jpg \
    resources/image/general_test/???AGU801.jpg \
    resources/image/general_test/???AKM065.jpg \
    resources/image/general_test/???AKQ291.jpg \
    resources/image/general_test/???AL0Q87.jpg \
    resources/image/general_test/???AM1186.jpg \
    resources/image/general_test/???AN4E10.jpg \
    resources/image/general_test/???AR9X49.jpg \
    resources/image/general_test/???AS9V79.jpg \
    resources/image/general_test/???AUU093.jpg \
    resources/image/general_test/???AY116F.jpg \
    resources/image/general_test/???AZ408T.jpg \
    resources/image/general_test/???C28888.jpg \
    resources/image/general_test/???R35779.jpg \
    resources/image/general_test/???ATK071.jpg \
    resources/image/general_test/???A51V39.jpg \
    resources/image/general_test/???AGH092.jpg \
    resources/image/general_test/???ALB022.jpg \
    resources/image/general_test/???AP0910.jpg \
    resources/image/general_test/???B683J8.jpg \
    resources/image/general_test/???D71603.jpg \
    resources/image/general_test/???J32500.jpg \
    resources/image/general_test/???JS6999.jpg \
    resources/image/general_test/???K62933.jpg \
    resources/image/general_test/???KT5583.jpg \
    resources/image/general_test/???AHP676.jpg \
    resources/image/general_test/???DTG667.jpg \
    resources/image/general_test/???E14579.jpg \
    resources/image/general_test/???E22602.jpg \
    resources/image/general_test/???E24494.jpg \
    resources/image/general_test/???E28437.jpg \
    resources/image/general_test/???G68991.jpg \
    resources/image/general_test/???H65817.jpg \
    resources/image/general_test/???JZ3999.jpg \
    resources/image/general_test/???KNG518.jpg \
    resources/image/general_test/???LS2999.jpg \
    resources/image/general_test/???MJY929.jpg \
    resources/image/general_test/???MN0888.jpg \
    resources/image/general_test/???NRL118.jpg \
    resources/image/general_test/???RB7992.jpg \
    resources/image/general_test/???A03168.jpg \
    resources/image/general_test/???A12210.jpg \
    resources/image/general_test/???A12903.jpg \
    resources/image/general_test/???A13840.jpg \
    resources/image/general_test/???A21027.jpg \
    resources/image/general_test/???A26M71.jpg \
    resources/image/general_test/???A50819.jpg \
    resources/image/general_test/???A54614.jpg \
    resources/image/general_test/???A68952.jpg \
    resources/image/general_test/???A72220.jpg \
    resources/image/general_test/???A88888.jpg \
    resources/image/general_test/???A95044.jpg \
    resources/image/general_test/???AA2270.jpg \
    resources/image/general_test/???AA4586.jpg \
    resources/image/general_test/???AA5547.jpg \
    resources/image/general_test/???AC1847.jpg \
    resources/image/general_test/???AM690M.jpg \
    resources/image/general_test/???B7C289.jpg \
    resources/image/general_test/???C01701.jpg \
    resources/image/general_test/???E6686V.jpg \
    resources/image/general_test/???F397C0.jpg \
    resources/image/general_test/???F99999.jpg \
    resources/image/general_test/???G70000.jpg \
    resources/image/general_test/???GZB388.jpg \
    resources/image/general_test/???GZJ021.jpg \
    resources/image/general_test/???JP291Q.jpg \
    resources/image/general_test/???L11921.jpg \
    resources/image/general_test/???L66736.jpg \
    resources/image/general_test/???LD1930.jpg \
    resources/image/general_test/???B3587???.jpg \
    resources/image/general_test/???B777C9.jpg \
    resources/image/general_test/???BE7773.jpg \
    resources/image/general_test/???A05H22.jpg \
    resources/image/general_test/???A07G31.jpg \
    resources/image/general_test/???A0PC37.jpg \
    resources/image/general_test/???A0PQ76.jpg \
    resources/image/general_test/???A2991D.jpg \
    resources/image/general_test/???A31Y83.jpg \
    resources/image/general_test/???A3685C.jpg \
    resources/image/general_test/???A3MA06.jpg \
    resources/image/general_test/???A53U19.jpg \
    resources/image/general_test/???A5RM87.jpg \
    resources/image/general_test/???A97971.jpg \
    resources/image/general_test/???A9NU97.jpg \
    resources/image/general_test/???A9YU86.jpg \
    resources/image/general_test/???AA8516.jpg \
    resources/image/general_test/???AED855.jpg \
    resources/image/general_test/???AL8387.jpg \
    resources/image/general_test/???AT1Y68.jpg \
    resources/image/general_test/???AT3597.jpg \
    resources/image/general_test/???AT8781.jpg \
    resources/image/general_test/???ATL269.jpg \
    resources/image/general_test/???AYN355.jpg \
    resources/image/general_test/???F8ZS83.JPG \
    resources/image/general_test/???G60009.jpg \
    resources/image/general_test/???GR0L16.jpg \
    resources/image/general_test/???A00T45.jpg \
    resources/image/general_test/???A09T87.jpg \
    resources/image/general_test/???A1T235.jpg \
    resources/image/general_test/???A22T43.jpg \
    resources/image/general_test/???A2F560.jpg \
    resources/image/general_test/???A30123.jpg \
    resources/image/general_test/???A45277.jpg \
    resources/image/general_test/???A80003.jpg \
    resources/image/general_test/???A80375.jpg \
    resources/image/general_test/???A85501.jpg \
    resources/image/general_test/???A85890.jpg \
    resources/image/general_test/???A87271.jpg \
    resources/image/general_test/???AA3610.jpg \
    resources/image/general_test/???AH8331.jpg \
    resources/image/general_test/???AJH155.jpg \
    resources/image/general_test/???AK169H.jpg \
    resources/image/general_test/???AL025S.jpg \
    resources/image/general_test/???AS3165.jpg \
    resources/image/general_test/???AT789S.jpg \
    resources/image/general_test/???ATH859.jpg \
    resources/image/general_test/???AUB816.jpg \
    resources/image/general_test/???AX688A.jpg \
    resources/image/general_test/???BBC666.jpg \
    resources/image/general_test/???EZM618.jpg \
    resources/image/general_test/???F71646.jpg \
    resources/image/general_test/???M12288.jpg \
    resources/image/general_test/???M69311.jpg \
    resources/image/general_test/???P77222.jpg \
    resources/image/general_test/???Q06417.jpg \
    resources/image/general_test/???Q0686???.jpg \
    resources/image/general_test/???Q15538.jpg \
    resources/image/general_test/???Q18632.jpg \
    resources/image/general_test/???Q19917.jpg \
    resources/image/general_test/???Q80197.jpg \
    resources/image/general_test/???QA2825.jpg \
    resources/image/general_test/???A2HQ34.JPG \
    resources/image/general_test/???A2TS00.JPG \
    resources/image/general_test/???A5DP12.JPG \
    resources/image/general_test/???A5J512.jpg \
    resources/image/general_test/???A5PJ05.JPG \
    resources/image/general_test/???A5Q951.jpg \
    resources/image/general_test/???A82349.jpg \
    resources/image/general_test/???A84266.JPG \
    resources/image/general_test/???A89311.JPG \
    resources/image/general_test/???A94372.JPG \
    resources/image/general_test/???A961F3.jpg \
    resources/image/general_test/???AA0825.JPG \
    resources/image/general_test/???AAA379.jpg \
    resources/image/general_test/???AAB457.JPG \
    resources/image/general_test/???AAC044.jpg \
    resources/image/general_test/???AAD348.jpg \
    resources/image/general_test/???AAF230.JPG \
    resources/image/general_test/???AB288Y.JPG \
    resources/image/general_test/???AB2893.JPG \
    resources/image/general_test/???AF9C00.JPG \
    resources/image/general_test/???AK9331.jpg \
    resources/image/general_test/???AL6212.jpg \
    resources/image/general_test/???AV0U41.jpg \
    resources/image/general_test/???B0K999.jpg \
    resources/image/general_test/???B2757B.jpg \
    resources/image/general_test/???B2LR57.jpg \
    resources/image/general_test/???B3RS91.jpg \
    resources/image/general_test/???B4051L.jpg \
    resources/image/general_test/???B577QK.jpg \
    resources/image/general_test/???B5PQ23.JPG \
    resources/image/general_test/???B5W601.JPG \
    resources/image/general_test/???B7VW40.jpg \
    resources/image/general_test/???B901BF.jpg \
    resources/image/general_test/???B972HL.jpg \
    resources/image/general_test/???BA103N.jpg \
    resources/image/general_test/???BA9H07.jpg \
    resources/image/general_test/???BB867A.jpg \
    resources/image/general_test/???BDB720.jpg \
    resources/image/general_test/???BE24Q7.jpg \
    resources/image/general_test/???BE609T.jpg \
    resources/image/general_test/???BK33E3.jpg \
    resources/image/general_test/???BP3T05.jpg \
    resources/image/general_test/???BR75Y3.jpg \
    resources/image/general_test/???BTT255.jpg \
    resources/image/general_test/???BW44R6.jpg \
    resources/image/general_test/???BZ756T.jpg \
    resources/image/general_test/???BZ89M9.jpg \
    resources/image/general_test/???CXE592.jpg \
    resources/image/general_test/???E9R439.JPG \
    resources/image/general_test/???OA2160.jpg \
    resources/image/general_test/???OA9112.jpg \
    resources/image/general_test/???OT9048.jpg \
    resources/image/general_test/???SD050L.JPG \
    resources/image/general_test/???SK903B.JPG \
    resources/image/general_test/???TD1291.jpg \
    resources/image/general_test/???VS1866.jpg \
    resources/image/general_test/???X30479.JPG \
    resources/image/general_test/???A0CP56.jpg \
    resources/image/general_test/???A20Q03.jpg \
    resources/image/general_test/???A36E80.jpg \
    resources/image/general_test/???A66U71.jpg \
    resources/image/general_test/???A6E176.jpg \
    resources/image/general_test/???A75976.jpg \
    resources/image/general_test/???A85Z95.jpg \
    resources/image/general_test/???A9YP07.jpg \
    resources/image/general_test/???AD6A99.jpg \
    resources/image/general_test/???ADW072.jpg \
    resources/image/general_test/???AHOG66.jpg \
    resources/image/general_test/???AL926V.jpg \
    resources/image/general_test/???AP0966.jpg \
    resources/image/general_test/???AQ5B65.jpg \
    resources/image/general_test/???AVW997.jpg \
    resources/image/general_test/???B551QV.jpg \
    resources/image/general_test/???B577CU.jpg \
    resources/image/general_test/???BGG522.jpg \
    resources/image/general_test/???BU5838.jpg \
    resources/image/general_test/???CTF181.jpg \
    resources/image/general_test/???DLA031.jpg \
    resources/image/general_test/???E2Y256.jpg \
    resources/image/general_test/???E75614.jpg \
    resources/image/general_test/???EB68W9.jpg \
    resources/image/general_test/???K91239.jpg \
    resources/image/general_test/???S33909.jpg \
    resources/image/general_test/???U00000.jpg \
    resources/image/general_test/???A82F36.jpg \
    resources/image/general_test/???A88888.jpg \
    resources/image/general_test/???K11978.jpg \
    resources/image/general_test/???B99999.jpg \
    resources/image/general_test/???BG0D80.jpg \
    resources/image/general_test/???BMW005.jpg \
    resources/image/general_test/???C33333.jpg \
    resources/image/general_test/???PE9218.jpg \
    resources/image/general_test/???CPB592.jpg \
    resources/image/general_test/???HB1508.jpg \
    resources/image/general_test/???AD2N68.jpg \
    resources/image/general_test/???AE8F80.jpg \
    resources/image/general_test/???A88888.jpg \
    resources/image/general_test/???B995EQ.jpg \
    resources/image/general_test/???BQG527.jpg \
    resources/image/general_test/???JRW350.jpg \
    resources/image/general_test/???KK5555.jpg \
    resources/image/general_test/???LD9016.jpg \
    resources/image/general_test/???Y44748.jpg \
    resources/image/general_test/???A16341.jpg \
    resources/image/general_test/???A1R272.jpg \
    resources/image/general_test/???AB4444.jpg \
    resources/image/native_test/GroundTruth_others.xml \
    resources/image/native_test/GroundTruth_windows.xml \
    resources/image/plate_detect.jpg \
    resources/image/plate_judge.jpg \
    resources/image/plate_locate.jpg \
    resources/image/plate_recognize.jpg \
    resources/image/test.jpg \
    resources/image/????????????.txt \
    resources/result/Result.xml \
    resources/result/accuracy.txt \
    resources/result/gridSearch.txt \
    resources/result/plateGroundTruth.txt \
    resources/text/batch_test_menu \
    resources/text/chinese_mapping \
    resources/text/dev_team \
    resources/text/main_menu \
    resources/text/province_mapping \
    resources/text/test_menu \
    resources/text/thanks \
    resources/text/train_menu \
    resources/train/ann.7z \
    resources/train/annCh.7z \
    resources/train/annGray.7z \
    resources/train/svm.7z \
    thirdparty/CMakeLists.txt \
    thirdparty/xmlParser/AFPL-license.txt

RESOURCES += \
    image.qrc
