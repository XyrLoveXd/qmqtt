/*
 * qmqtt_socketinterface.h - qmqtt socket interface header
 *
 * Copyright (c) 2013  Ery Lee <ery.lee at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of mqttc nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef QMQTT_SOCKET_INTERFACE_H
#define QMQTT_SOCKET_INTERFACE_H

#include <QHostAddress>
#include <QIODevice>

namespace QMQTT
{

class SocketInterface : public QIODevice
{
    Q_OBJECT
public:
    explicit SocketInterface(QObject* parent = NULL) : QIODevice(parent)
    {
        setOpenMode(QIODevice::ReadWrite);
    }
    virtual	~SocketInterface() {}

    virtual void connectToHost(const QHostAddress& address, quint16 port) = 0;
    virtual void connectToHost(const QString& hostName, quint16 port) = 0;
    virtual void disconnectFromHost() = 0;
    virtual QAbstractSocket::SocketState state() const = 0;
    virtual bool atEnd() const = 0;
    virtual bool waitForBytesWritten(int msecs) = 0;
    virtual QAbstractSocket::SocketError error() const = 0;
    virtual qint64 readData(char* data, qint64 maxlen) = 0;
    virtual qint64 writeData(const char* data, qint64 len) = 0;

signals:
    void connected();
    void disconnected();
    void readyRead();
    void error(QAbstractSocket::SocketError socketError);
};

}

#endif // QMQTT_SOCKET_INTERFACE_H
