/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qmessage.h"
#include "qmessage_p.h"

#include <QtUml/QMessageEnd>
#include <QtUml/QInteraction>
#include <QtUml/QValueSpecification>
#include <QtUml/QConnector>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

namespace QtUml
{

QMessagePrivate::QMessagePrivate() :
    messageSort(QtUmlNS::MessageSynchCall),
    signature(0),
    receiveEvent(0),
    interaction(0),
    sendEvent(0),
    connector(0)
{
}

QMessagePrivate::~QMessagePrivate()
{
}

/*!
    \class QMessage

    \inmodule QtUml

    \brief A message defines a particular communication between lifelines of an interaction.
 */

QMessage::QMessage(QWrappedObject *wrapper, QWrappedObject *parent) :
    QNamedElement(*new QMessagePrivate, wrapper, parent)
{
    setPropertyData();
}

QMessage::QMessage(QMessagePrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QNamedElement(dd, wrapper, parent)
{
    setPropertyData();
}

QMessage::~QMessage()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QMessage
// ---------------------------------------------------------------

/*!
    The sort of communication reflected by the Message
 */
QtUmlNS::MessageSort QMessage::messageSort() const
{
    // This is a read-write attribute

    Q_D(const QMessage);
    return d->messageSort;
}

void QMessage::setMessageSort(QtUmlNS::MessageSort messageSort)
{
    // This is a read-write attribute

    Q_D(QMessage);
    if (d->messageSort != messageSort) {
        d->messageSort = messageSort;
    }
    d->modifiedResettableProperties << QString::fromLatin1("messageSort");
}

void QMessage::unsetMessageSort()
{
    setMessageSort(QtUmlNS::MessageSynchCall);
    Q_D(QMessage);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("messageSort"));
}

/*!
    The derived kind of the Message (complete, lost, found or unknown)
 */
QtUmlNS::MessageKind QMessage::messageKind() const
{
    // This is a read-only derived attribute

    qWarning("QMessage::messageKind: to be implemented (this is a derived attribute)");

    return QtUmlNS::MessageKind(); // change here to your derived return
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QMessage
// ---------------------------------------------------------------

/*!
    The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
 */
QNamedElement *QMessage::signature() const
{
    // This is a read-write association end

    Q_D(const QMessage);
    return d->signature;
}

void QMessage::setSignature(QNamedElement *signature)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (d->signature != signature) {
        d->signature = signature;
    }
}

/*!
    The arguments of the Message
 */
QList<QValueSpecification *> QMessage::arguments() const
{
    // This is a read-write association end

    Q_D(const QMessage);
    return d->arguments;
}

void QMessage::addArgument(QValueSpecification *argument)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (!d->arguments.contains(argument)) {
        d->arguments.append(argument);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(argument));
    }
}

void QMessage::removeArgument(QValueSpecification *argument)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (d->arguments.contains(argument)) {
        d->arguments.removeAll(argument);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(argument));
    }
}

/*!
    References the Receiving of the Message
 */
QMessageEnd *QMessage::receiveEvent() const
{
    // This is a read-write association end

    Q_D(const QMessage);
    return d->receiveEvent;
}

void QMessage::setReceiveEvent(QMessageEnd *receiveEvent)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (d->receiveEvent != receiveEvent) {
        d->receiveEvent = receiveEvent;
    }
}

/*!
    The enclosing Interaction owning the Message
 */
QInteraction *QMessage::interaction() const
{
    // This is a read-write association end

    Q_D(const QMessage);
    return d->interaction;
}

void QMessage::setInteraction(QInteraction *interaction)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (d->interaction != interaction) {
        // Adjust opposite property
        if (d->interaction)
            d->interaction->removeMessage(this);

        d->interaction = interaction;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamedElementPrivate *>(d))->setNamespace_(qwrappedobject_cast<QNamespace *>(interaction));

        // Adjust opposite property
        if (interaction)
            interaction->addMessage(this);
    }
}

/*!
    References the Sending of the Message.
 */
QMessageEnd *QMessage::sendEvent() const
{
    // This is a read-write association end

    Q_D(const QMessage);
    return d->sendEvent;
}

void QMessage::setSendEvent(QMessageEnd *sendEvent)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (d->sendEvent != sendEvent) {
        d->sendEvent = sendEvent;
    }
}

/*!
    The Connector on which this Message is sent.
 */
QConnector *QMessage::connector() const
{
    // This is a read-write association end

    Q_D(const QMessage);
    return d->connector;
}

void QMessage::setConnector(QConnector *connector)
{
    // This is a read-write association end

    Q_D(QMessage);
    if (d->connector != connector) {
        d->connector = connector;
    }
}

void QMessage::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageSort")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageSort")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageSort")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The sort of communication reflected by the Message");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageSort")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageSort")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageSort")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageKind")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageKind")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageKind")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The derived kind of the Message (complete, lost, found or unknown)");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageKind")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageKind")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("messageKind")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("signature")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("signature")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("signature")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The signature of the Message is the specification of its content. It refers either an Operation or a Signal.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("signature")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("signature")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("signature")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("arguments")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("arguments")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("arguments")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The arguments of the Message");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("arguments")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("arguments")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::ownedElements");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("arguments")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("receiveEvent")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("receiveEvent")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("receiveEvent")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("References the Receiving of the Message");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("receiveEvent")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("receiveEvent")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("receiveEvent")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("interaction")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("interaction")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("interaction")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The enclosing Interaction owning the Message");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("interaction")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("interaction")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QNamedElement::namespace");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("interaction")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QInteraction::message");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("sendEvent")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("sendEvent")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("sendEvent")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("References the Sending of the Message.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("sendEvent")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("sendEvent")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("sendEvent")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("connector")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("connector")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("connector")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The Connector on which this Message is sent.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("connector")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("connector")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QMessage")][QString::fromLatin1("connector")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QNamedElement::setPropertyData();
}

}

QT_END_NAMESPACE

#include "moc_qmessage.cpp"

