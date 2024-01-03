#ifndef MARPAESLIFJAVA_H
#define MARPAESLIFJAVA_H

#include <jni.h>
#include <marpaESLIFJava/export.h>

#ifdef __cplusplus
extern "C" {
#endif
  marpaESLIFJava_EXPORT jint         JNICALL JNI_OnLoad                                                      (JavaVM *vmp, void* reservedp);
  marpaESLIFJava_EXPORT void         JNICALL JNI_OnUnLoad                                                    (JavaVM *vmp, void* reservedp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIF_jniNew                              (JNIEnv *envp, jobject eslifp, jint indice);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIF_jniJavaVersion                      (JNIEnv *envp, jclass classp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIF_jniJavaVersionMajor                 (JNIEnv *envp, jclass classp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIF_jniJavaVersionMinor                 (JNIEnv *envp, jclass classp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIF_jniJavaVersionPatch                 (JNIEnv *envp, jclass classp);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIF_jniVersion                          (JNIEnv *envp, jobject eslifp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIF_jniVersionMajor                     (JNIEnv *envp, jobject eslifp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIF_jniVersionMinor                     (JNIEnv *envp, jobject eslifp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIF_jniVersionPatch                     (JNIEnv *envp, jobject eslifp);
  /* marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIF_jniFree                             (JNIEnv *envp, jobject eslifp); */
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFGrammar_jniNew                       (JNIEnv *envp, jobject eslifGrammarp, jbyteArray utf8byteArrayp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIFGrammar_jniNgrammar                  (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jint         JNICALL Java_org_parser_marpa_ESLIFGrammar_jniCurrentLevel              (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniCurrentDescription        (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniDescriptionByLevel        (JNIEnv *envp, jobject eslifGrammarp, jint level);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniCurrentRuleIds            (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniCurrentSymbolIds          (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRuleIdsByLevel            (JNIEnv *envp, jobject eslifGrammarp, jint level);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniSymbolIdsByLevel          (JNIEnv *envp, jobject eslifGrammarp, jint level);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRuleDisplay               (JNIEnv *envp, jobject eslifGrammarp, jint rule);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniSymbolDisplay             (JNIEnv *envp, jobject eslifGrammarp, jint symbol);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRuleShow                  (JNIEnv *envp, jobject eslifGrammarp, jint rule);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRuleDisplayByLevel        (JNIEnv *envp, jobject eslifGrammarp, jint level, jint rule);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniSymbolDisplayByLevel      (JNIEnv *envp, jobject eslifGrammarp, jint level, jint symbol);
  marpaESLIFJava_EXPORT jintArray    JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRuleShowByLevel           (JNIEnv *envp, jobject eslifGrammarp, jint level, jint rule);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniShow                      (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniShowByLevel               (JNIEnv *envp, jobject eslifGrammarp, jint level);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFGrammar_jniParse                     (JNIEnv *envp, jobject eslifGrammarp, jobject eslifRecognizerInterfacep, jobject eslifValueInterfacep);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniProperties                (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniPropertiesByLevel         (JNIEnv *envp, jobject eslifGrammarp, jint level);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRuleProperties            (JNIEnv *envp, jobject eslifGrammarp, jint rule);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniRulePropertiesByLevel     (JNIEnv *envp, jobject eslifGrammarp, jint level, jint rule);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniSymbolProperties          (JNIEnv *envp, jobject eslifGrammarp, jint symbol);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFGrammar_jniSymbolPropertiesByLevel   (JNIEnv *envp, jobject eslifGrammarp, jint level, jint symbol);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFGrammar_jniFree                      (JNIEnv *envp, jobject eslifGrammarp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniNew                    (JNIEnv *envp, jobject eslifRecognizerp, jobject eslifGrammarp, jboolean shallow);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniShare                  (JNIEnv *envp, jobject eslifRecognizerp, jobject eslifRecognizerSharedp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniUnshare                (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniPeek                   (JNIEnv *envp, jobject eslifRecognizerp, jobject eslifRecognizerPeekedp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniUnpeek                 (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniScan                   (JNIEnv *envp, jobject eslifRecognizerp, jboolean initialEvents);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniResume                 (JNIEnv *envp, jobject eslifRecognizerp, jint deltaLength);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniAlternative            (JNIEnv *envp, jobject eslifRecognizerp, jstring namep, jobject objectp, jint grammarLengthi);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniAlternativeComplete    (JNIEnv *envp, jobject eslifRecognizerp, jint lengthi);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniAlternativeRead        (JNIEnv *envp, jobject eslifRecognizerp, jstring namep, jobject objectp, jint lengthi, jint grammarLengthi);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniNameTry                (JNIEnv *envp, jobject eslifRecognizerp, jstring namep);
  marpaESLIFJava_EXPORT jlong        JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniDiscard                (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniDiscardTry             (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jobjectArray JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniNameExpected           (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniIsEof                  (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniIsStartComplete        (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniIsExhausted            (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniSetExhaustedFlag       (JNIEnv *envp, jobject eslifRecognizerp, jboolean flag);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniIsCanContinue          (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniRead                   (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniInput                  (JNIEnv *envp, jobject eslifRecognizerp, jint offset, jint length);
  marpaESLIFJava_EXPORT jlong        JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniInputLength            (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniError                  (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniNameLastPause          (JNIEnv *envp, jobject eslifRecognizerp, jstring namep);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniNameLastTry            (JNIEnv *envp, jobject eslifRecognizerp, jstring namep);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniDiscardLastTry         (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniDiscardLast            (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jobjectArray JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniEvent                  (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jobjectArray JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniProgress               (JNIEnv *envp, jobject eslifRecognizerp, jint starti, jint endi);
  marpaESLIFJava_EXPORT jlong        JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniLastCompletedOffset    (JNIEnv *envp, jobject eslifRecognizerp, jstring namep);
  marpaESLIFJava_EXPORT jlong        JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniLastCompletedLength    (JNIEnv *envp, jobject eslifRecognizerp, jstring namep);
  marpaESLIFJava_EXPORT jlong        JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniLine                   (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jlong        JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniColumn                 (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniEventOnOff             (JNIEnv *envp, jobject eslifRecognizerp, jstring symbolp, jobjectArray eventTypesp, jboolean onOff);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniHookDiscard            (JNIEnv *envp, jobject eslifRecognizerp, jboolean onOff);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniHookDiscardSwitch      (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniProgressLog            (JNIEnv *envp, jobject eslifRecognizerp, jint starti, jint endi, jobject levelp);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniSymbolTry              (JNIEnv *envp, jobject eslifRecognizerp, jobject eslifSymbolp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFRecognizer_jniFree                   (JNIEnv *envp, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFValue_jniNew                         (JNIEnv *envp, jobject eslifValuep, jobject eslifRecognizerp);
  marpaESLIFJava_EXPORT jboolean     JNICALL Java_org_parser_marpa_ESLIFValue_jniValue                       (JNIEnv *envp, jobject eslifValuep);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFValue_jniFree                        (JNIEnv *envp, jobject eslifValuep);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFJSONEncoder_jniNew                   (JNIEnv *envp, jobject eslifJSONEncoderp, jboolean strict);
  marpaESLIFJava_EXPORT jstring      JNICALL Java_org_parser_marpa_ESLIFJSONEncoder_jniEncode                (JNIEnv *envp, jobject eslifJSONEncoderp, jobject o);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFJSONEncoder_jniFree                  (JNIEnv *envp, jobject eslifJSONEncoderp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFJSONDecoder_jniNew                   (JNIEnv *envp, jobject eslifJSONDecoderp, jboolean strict);
  marpaESLIFJava_EXPORT jobject      JNICALL Java_org_parser_marpa_ESLIFJSONDecoder_jniDecode                (JNIEnv *envp, jobject eslifJSONDecoderp, jobject eslifRecognizerInterfacep, jobject eslifDecodeOptionp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFJSONDecoder_jniFree                  (JNIEnv *envp, jobject eslifJSONDecoderp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFSymbol_jniNew                        (JNIEnv *envp, jobject eslifSymbolp, jstring type, jbyteArray utf8byteArrayp, jstring modifiers, jbyteArray substitutionUtf8byteArrayp, jstring substitutionModifiersp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFSymbol_jniMetaNew                    (JNIEnv *envp, jobject eslifSymbolp, jobject eslifGrammarp, jstring symbolp);
  marpaESLIFJava_EXPORT jbyteArray   JNICALL Java_org_parser_marpa_ESLIFSymbol_jniTest                       (JNIEnv *envp, jobject eslifSymbolp, jbyteArray byteArrayp);
  marpaESLIFJava_EXPORT void         JNICALL Java_org_parser_marpa_ESLIFSymbol_jniFree                       (JNIEnv *envp, jobject eslifSymbolp);
#ifdef __cplusplus
}
#endif

#endif /* MARPAESLIFJAVA_H */
