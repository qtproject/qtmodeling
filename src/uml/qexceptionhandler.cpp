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

#include "qexceptionhandler.h"
#include "qexceptionhandler_p.h"

#include <QtUml/QObjectNode>
#include <QtUml/QClassifier>
#include <QtUml/QExecutableNode>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

namespace QtUml
{

QExceptionHandlerPrivate::QExceptionHandlerPrivate() :
    handlerBody(0),
    protectedNode(0),
    exceptionInput(0)
{
}

QExceptionHandlerPrivate::~QExceptionHandlerPrivate()
{
}

/*!
    \class QExceptionHandler

    \inmodule QtUml

    \brief An exception handler is an element that specifies a body to execute in case the specified exception occurs during the execution of the protected node.
 */

QExceptionHandler::QExceptionHandler(QWrappedObject *wrapper, QWrappedObject *parent) :
    QElement(*new QExceptionHandlerPrivate, wrapper, parent)
{
    setPropertyData();
}

QExceptionHandler::QExceptionHandler(QExceptionHandlerPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QElement(dd, wrapper, parent)
{
    setPropertyData();
}

QExceptionHandler::~QExceptionHandler()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QExceptionHandler
// ---------------------------------------------------------------

/*!
    A node that is executed if the handler satisfies an uncaught exception.
 */
QExecutableNode *QExceptionHandler::handlerBody() const
{
    // This is a read-write association end

    Q_D(const QExceptionHandler);
    return d->handlerBody;
}

void QExceptionHandler::setHandlerBody(QExecutableNode *handlerBody)
{
    // This is a read-write association end

    Q_D(QExceptionHandler);
    if (d->handlerBody != handlerBody) {
        d->handlerBody = handlerBody;
    }
}

/*!
    The kind of instances that the handler catches. If an exception occurs whose type is any of the classifiers in the set, the handler catches the exception and executes its body.
 */
QSet<QClassifier *> QExceptionHandler::exceptionTypes() const
{
    // This is a read-write association end

    Q_D(const QExceptionHandler);
    return d->exceptionTypes;
}

void QExceptionHandler::addExceptionType(QClassifier *exceptionType)
{
    // This is a read-write association end

    Q_D(QExceptionHandler);
    if (!d->exceptionTypes.contains(exceptionType)) {
        d->exceptionTypes.insert(exceptionType);
    }
}

void QExceptionHandler::removeExceptionType(QClassifier *exceptionType)
{
    // This is a read-write association end

    Q_D(QExceptionHandler);
    if (d->exceptionTypes.contains(exceptionType)) {
        d->exceptionTypes.remove(exceptionType);
    }
}

/*!
    The node protected by the handler. The handler is examined if an exception propagates to the outside of the node.
 */
QExecutableNode *QExceptionHandler::protectedNode() const
{
    // This is a read-write association end

    Q_D(const QExceptionHandler);
    return d->protectedNode;
}

void QExceptionHandler::setProtectedNode(QExecutableNode *protectedNode)
{
    // This is a read-write association end

    Q_D(QExceptionHandler);
    if (d->protectedNode != protectedNode) {
        // Adjust opposite property
        if (d->protectedNode)
            d->protectedNode->removeHandler(this);

        d->protectedNode = protectedNode;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->setOwner(qwrappedobject_cast<QElement *>(protectedNode));

        // Adjust opposite property
        if (protectedNode)
            protectedNode->addHandler(this);
    }
}

/*!
    An object node within the handler body. When the handler catches an exception, the exception token is placed in this node, causing the body to execute.
 */
QObjectNode *QExceptionHandler::exceptionInput() const
{
    // This is a read-write association end

    Q_D(const QExceptionHandler);
    return d->exceptionInput;
}

void QExceptionHandler::setExceptionInput(QObjectNode *exceptionInput)
{
    // This is a read-write association end

    Q_D(QExceptionHandler);
    if (d->exceptionInput != exceptionInput) {
        d->exceptionInput = exceptionInput;
    }
}

void QExceptionHandler::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("handlerBody")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("handlerBody")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("handlerBody")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("A node that is executed if the handler satisfies an uncaught exception.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("handlerBody")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("handlerBody")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("handlerBody")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionTypes")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionTypes")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionTypes")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The kind of instances that the handler catches. If an exception occurs whose type is any of the classifiers in the set, the handler catches the exception and executes its body.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionTypes")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionTypes")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionTypes")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("protectedNode")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("protectedNode")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("protectedNode")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The node protected by the handler. The handler is examined if an exception propagates to the outside of the node.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("protectedNode")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("protectedNode")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::owner");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("protectedNode")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QExecutableNode::handler");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionInput")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionInput")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionInput")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("An object node within the handler body. When the handler catches an exception, the exception token is placed in this node, causing the body to execute.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionInput")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionInput")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QExceptionHandler")][QString::fromLatin1("exceptionInput")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QElement::setPropertyData();
}

}

QT_END_NAMESPACE

#include "moc_qexceptionhandler.cpp"

