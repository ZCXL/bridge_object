//
// Created by �쳬 on 2017/3/16.
//

#ifndef BRIDGE_STRING_H
#define BRIDGE_STRING_H
#include "bridge.h"
#include "java.h"
namespace java {
    class JString: public JObject, public _jstring {
    public:
        JString();
        JString(jstring str);
        
        virtual ~JString();

    protected:
        JString(std::string className);

	private:
		jfieldID _field_value;
	    jfieldID _field_hash;
	    jfieldID _field_serialVersionUID;
	    jfieldID _field_serialPersistentFields;
	    jfieldID _field_CASE_INSENSITIVE_ORDER;
	    jmethodID _method_equals_6ca70bf503de7f5300a61e8a40db9472;
	    jmethodID _method_toString_cc048952172904474220d0f22ee9fe3d;
	    jmethodID _method_hashCode_650644593323aca8feb6b5aae1fa6fc8;
	    jmethodID _method_compareTo_6d2b73a137a3fad8918b6872fbc26412;
	    jmethodID _method_compareTo_17b85043609914f43804793a144b3926;
	    jmethodID _method_indexOf_f98b55b0b8521057579be5b35c49abb1;
	    jmethodID _method_indexOf_4f359b7d4aea6081093ea623b06862b8;
	    jmethodID _method_indexOf_7f6f1efbd803872233f13ebda1d42452;
	    jmethodID _method_indexOf_122a5a2d83329d8f693471c34f9a95de;
	    jmethodID _method_valueOf_7ba8da1f5a4f20331f6f4c550ff9c390;
	    jmethodID _method_valueOf_b9956756b591d179c50a71adc128b393;
	    jmethodID _method_valueOf_19a5f4c8e34b25b1f2ea8ed9131976d9;
	    jmethodID _method_valueOf_8774a3a38e1660f5bdf4f649e79c52c4;
	    jmethodID _method_valueOf_4e5b7b1db4de31c654bc893eda4b59c6;
	    jmethodID _method_valueOf_3d2d021e4f38c288647a5297bb4fbff0;
	    jmethodID _method_valueOf_15ca47c2ae2b05d454186d5a630ed14b;
	    jmethodID _method_valueOf_01d4d52a6e6ebb66d9adc13f070ad156;
	    jmethodID _method_valueOf_4e26a7e4cf9eac77be6d133114904d6f;
	    jmethodID _method_length_756688f821475968b201654989dda9f1;
	    jmethodID _method_isEmpty_ff5d571e3e78af98fd041b1e62c93363;
	    jmethodID _method_charAt_02c857f2bfe9af9bd09fcb676a93ccb8;
	    jmethodID _method_codePointAt_a4a16c952d0d7e29f8ae3f1feecfce72;
	    jmethodID _method_codePointBefore_2ed02e3533dcce2edc7474f8d71e6003;
	    jmethodID _method_codePointCount_ddf0e51ce915092a32eaefa7fc43e883;
	    jmethodID _method_offsetByCodePoints_30f4d9bbb78d0e3979df02bfef26a3a6;
	    jmethodID _method_getChars_323b57c4a8fbd83cc22569f3890fd34d;
	    jmethodID _method_getBytes_14f1fc6bb35f0c128db17a115aafd9a4;
	    jmethodID _method_getBytes_86add6f91a0d4054cb5b6a742b0672d7;
	    jmethodID _method_getBytes_1d390f76c3e390c1e80843f2b859179c;
	    jmethodID _method_getBytes_60b6da6d8d9aa7b21f79cf89302b0273;
	    jmethodID _method_contentEquals_7b804d9b94fc66a2ffec085fcf614c9a;
	    jmethodID _method_contentEquals_0924870966d9bfed53c0effcd03c0717;
	    jmethodID _method_equalsIgnoreCase_4e6a92a12ff302537ecc43627baf8efa;
	    jmethodID _method_compareToIgnoreCase_3a934cdb4f7365b63b840b1f34e07a84;
	    jmethodID _method_regionMatches_14882413e33b532dbd700ed83a91ba0b;
	    jmethodID _method_regionMatches_66b216fbac9e5225e52d2073509a7123;
	    jmethodID _method_startsWith_dc8e58fa889b59673ebd278b6e2dd9c2;
	    jmethodID _method_startsWith_1d92c92efd2af2bb0707ed08e4cc1f72;
	    jmethodID _method_endsWith_a5b802ebe31f1d53fa1bffb3a59752f6;
	    jmethodID _method_lastIndexOf_658d312f2638a66129cdf52cd5a6bf9a;
	    jmethodID _method_lastIndexOf_da651ef0f42c0baaed4db2f914233e4e;
	    jmethodID _method_lastIndexOf_e838a30270082552610fc5816029bb57;
	    jmethodID _method_lastIndexOf_c9ade705ff1b41a8fd0e4119f6693cad;
	    jmethodID _method_substring_bdcadd73e21aab2b17bcae95680babf0;
	    jmethodID _method_substring_332203d1cb1b723c9921cb9abca4d4f4;
	    jmethodID _method_subSequence_74f5c5d9e224191a2a539bc03584f754;
	    jmethodID _method_concat_d505da336b657c1e0cf88a75752e3373;
	    jmethodID _method_replace_ddfa2c593d1d66347f8eb4e3004edce2;
	    jmethodID _method_replace_f0d5f563a39b63232090d5d4a2aa8cc5;
	    jmethodID _method_matches_801de4773a32f60ab869ff80950d80f5;
	    jmethodID _method_contains_ac9d88db01f78ae94e6cca8e1b689f71;
	    jmethodID _method_replaceFirst_385075152494768539aa33f360927d2c;
	    jmethodID _method_replaceAll_2f1980fcf04f16551265b61506f942ef;
	    jmethodID _method_split_6cad25a97336e11d52b1f923458867ac;
	    jmethodID _method_split_5fccd9626b876cb2b06d3ac4d24e394b;
	    jmethodID _method_join_10d549fa43a08bbefbe505ea06f659d9;
	    jmethodID _method_join_97fd5a8cc62e5103908f9700191fd424;
	    jmethodID _method_toLowerCase_200c48c38023b948f1b1cabbda8b09ae;
	    jmethodID _method_toLowerCase_5fe426b2ec026e84c290ab1a7bcdf087;
	    jmethodID _method_toUpperCase_dcd5af0cd3696c52221c5a30d146394c;
	    jmethodID _method_toUpperCase_a169a3618adbc7a6f2443b77cb69d615;
	    jmethodID _method_trim_87def362105b5bcc82f6808b88cd07ed;
	    jmethodID _method_toCharArray_83982b58b24d1ca37529fbd326460657;
	    jmethodID _method_format_0d223a681ed96d9c944c873a673fe2b9;
	    jmethodID _method_format_9b9f3f31861d6e377e65c9e974c0c6f9;
	    jmethodID _method_copyValueOf_d707ff6a454fc9be4c5a1e9648e95d78;
	    jmethodID _method_copyValueOf_6fa482d07701462bf52ab18cea006a50;
	    jmethodID _method_intern_9db0de96a26acace98ccd2840d10c152;
	    jmethodID _method_wait_ed77e8f91c0aca7e8b75687cc9236602;
	    jmethodID _method_wait_1a147d3d0b857527a9a1a3db795026df;
	    jmethodID _method_wait_ba9c31b5aea0f07668020e0d8470b369;
	    jmethodID _method_getClass_50f362ecd44fc508b3fd6b5ec2ed24da;
	    jmethodID _method_notify_fe8850ad55d0489ce85e76f863c3a615;
	    jmethodID _method_notifyAll_54586b80b3c1f3e670bbcdde310d2ce5;
	    jmethodID _method_chars_0b392264f1893f3c34f54232baa10be7;
	    jmethodID _method_codePoints_d8f8703c765a2780e7ed494fcacfa7aa;
	    jmethodID _method_init_cded731bfba5574e501cb4a8230d7284;
	    jmethodID _method_init_960b5695470564e03d2a893ea1b897bf;
	    jmethodID _method_init_c17889719ec3c93ea93758b13e345f50;
	    jmethodID _method_init_cfc1aa8df3514a32870dad982c87e889;
	    jmethodID _method_init_f9f4360800484e3f8b5d01b79461bdaa;
	    jmethodID _method_init_00a4945728ac06971fb18e2132bc0101;
	    jmethodID _method_init_916a3f211745a74997604b8db6d99d16;
	    jmethodID _method_init_51ad331339ee99bda3e3cc9e0b2e0917;
	    jmethodID _method_init_10004391a72214dc168094a7e560cb95;
	    jmethodID _method_init_052a92f90143e4036689f5f864a5962e;
	    jmethodID _method_init_8c521e26b0f616ac8bc446ce4cd13179;
	    jmethodID _method_init_676695c6109226325b8cb5243043e97d;
	    jmethodID _method_init_038d2c1879b7adfae534fd01e5858107;
	    jmethodID _method_init_7d271067ee3a9ca1930279a94ff38b0a;
	    jmethodID _method_init_3c9bde999eecd16f9d028e0f60677034;
    };
}
#endif //BRIDGE_STRING_H
