#include "com_km_chat_custom_AESMessageMapper.h"
#include "aes.h"

#include <iostream>

jbyteArray Java_com_km_chat_custom_AESMessageMapper_encode
  (JNIEnv* jenv, jobject obj, jbyteArray message, jbyteArray key)
{
    uint8_t output[16];

    auto length = jenv->GetArrayLength(message);
    auto cppMessage = new uint8_t[length];
    jenv->GetByteArrayRegion(message, 0, length, reinterpret_cast<jbyte*>(cppMessage));
    for(size_t i = length; i < 16; ++i)
    {
        cppMessage[i] = ' ';
    }
//    length = jenv->GetArrayLength(key);
    uint8_t cppKey[] = "cryptosystemaess";
    //jenv->GetByteArrayRegion(key, 0, length, reinterpret_cast<jbyte*>(cppKey));

    AES128_ECB_encrypt(cppMessage, cppKey, output);

    delete cppMessage;
    cppMessage = nullptr;

    auto jOutput = jenv->NewByteArray(16);
    jenv->SetByteArrayRegion(jOutput, 0, 16, reinterpret_cast<jbyte*>(output));
    return jOutput;
}

jbyteArray Java_com_km_chat_custom_AESMessageMapper_decode
  (JNIEnv* jenv, jobject obj, jbyteArray message, jbyteArray key)
{
    uint8_t output[16];

    auto length = jenv->GetArrayLength(message);
    auto cppMessage = new uint8_t[16];
    jenv->GetByteArrayRegion(message, 0, length, reinterpret_cast<jbyte*>(cppMessage));
    for(size_t i = length; i < 16; ++i)
    {
        cppMessage[i] = '0';
    }
//    length = jenv->GetArrayLength(key);
    uint8_t cppKey[] = "cryptosystemaess";
    //jenv->GetByteArrayRegion(key, 0, length, reinterpret_cast<jbyte*>(cppKey));

    AES128_ECB_decrypt(cppMessage, cppKey, output);

    delete cppMessage;
    cppMessage = nullptr;

    auto jOutput = jenv->NewByteArray(16);
    jenv->SetByteArrayRegion(jOutput, 0, 16, reinterpret_cast<jbyte*>(output));
    return jOutput;
}

