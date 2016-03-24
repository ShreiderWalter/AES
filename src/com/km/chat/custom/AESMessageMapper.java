package com.km.chat.custom;

/**
 * Created by Aliaksandr_Kachurka on 3/24/2016.
 */
public class AESMessageMapper implements MessageMapper {

    static{
        System.load("/home/walter/libAES.so");
    }

    @Override
    native public byte[] encode(byte[] message, byte[] key);

    @Override
    native public byte[] decode(byte[] cipher, byte[] key);
}
