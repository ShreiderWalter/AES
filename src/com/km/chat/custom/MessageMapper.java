package com.km.chat.custom;

/**
 * Created by Aliaksandr_Kachurka on 3/24/2016.
 */
public interface MessageMapper {

    byte[] encode(byte[] message, byte[] key);

    byte[] decode(byte[] cipher, byte[] key);
}
