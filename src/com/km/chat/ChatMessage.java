package com.km.chat;

import java.io.Serializable;

import com.km.chat.custom.AESMessageMapper;
import com.km.chat.custom.IdentityMessageMapper;
import com.km.chat.custom.MessageMapper;

/*
 * This class defines the different type of messages that will be exchanged between the
 * Clients and the Server.
 * When talking from a Java Client to a Java Server a lot easier to pass Java objects, no
 * need to count bytes or to wait for a line feed at the end of the frame
 */
class ChatMessage implements Serializable {

    private static MessageMapper messageMapper = new AESMessageMapper();
    private byte[] key = new byte[0];

    protected static final long serialVersionUID = 1112122200L;

    // The different types of message sent by the Client
    // WHOISIN to receive the list of the users connected
    // MESSAGE an ordinary message
    // LOGOUT to disconnect from the Server
    static final int WHOISIN = 0, MESSAGE = 1, LOGOUT = 2;
    private int type;
    private byte[] cipher;

    // constructor
    ChatMessage(int type, String message) {
        this.type = type;

        byte[] messageBytes = message.getBytes();
        this.cipher = messageMapper.encode(messageBytes, key);
    }

    // getters
    int getType() {
        return type;
    }

    String getMessage() {
        return new String(messageMapper.decode(cipher, key));
    }

    byte[] getCipher() {
        return cipher;
    }
}
