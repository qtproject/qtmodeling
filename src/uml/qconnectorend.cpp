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

#include "qconnectorend.h"
#include "qconnectorend_p.h"

#include "qconnectableelement_p.h"

#include <QtUml/QProperty>
#include <QtUml/QConnectableElement>

QT_BEGIN_NAMESPACE_QTUML

QConnectorEndPrivate::QConnectorEndPrivate() :
    role(0),
    partWithPort(0)
{
}

QConnectorEndPrivate::~QConnectorEndPrivate()
{
}

/*!
    \class QConnectorEnd

    \inmodule QtUml

    \brief A connector end is an endpoint of a connector, which attaches the connector to a connectable element. Each connector end is part of one connector.
 */

QConnectorEnd::QConnectorEnd(QWrappedObject *parent, QWrappedObject *wrapper) :
    QMultiplicityElement(*new QConnectorEndPrivate, parent, wrapper)
{
}

QConnectorEnd::QConnectorEnd(QConnectorEndPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QMultiplicityElement(dd, parent, wrapper)
{
}

QConnectorEnd::~QConnectorEnd()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QConnectorEnd
// ---------------------------------------------------------------

/*!
    The connectable element attached at this connector end. When an instance of the containing classifier is created, a link may (depending on the multiplicities) be created to an instance of the classifier that types this connectable element.
 */
QConnectableElement *QConnectorEnd::role() const
{
    // This is a read-write association end

    Q_D(const QConnectorEnd);
    return d->role;
}

void QConnectorEnd::setRole(QConnectableElement *role)
{
    // This is a read-write association end

    Q_D(QConnectorEnd);
    if (d->role != role) {
        // Adjust opposite property
        if (d->role)
            (qwrappedobject_cast<QConnectableElementPrivate *>(d->role->d_func()))->removeEnd(this);

        d->role = role;

        // Adjust opposite property
        if (role)
            (qwrappedobject_cast<QConnectableElementPrivate *>(role->d_func()))->addEnd(this);
    }
}

/*!
    Indicates the role of the internal structure of a classifier with the port to which the connector end is attached.
 */
QProperty *QConnectorEnd::partWithPort() const
{
    // This is a read-write association end

    Q_D(const QConnectorEnd);
    return d->partWithPort;
}

void QConnectorEnd::setPartWithPort(QProperty *partWithPort)
{
    // This is a read-write association end

    Q_D(QConnectorEnd);
    if (d->partWithPort != partWithPort) {
        d->partWithPort = partWithPort;
    }
}

/*!
    A derived association referencing the corresponding association end on the association which types the connector owing this connector end. This association is derived by selecting the association end at the same place in the ordering of association ends as this connector end.
 */
QProperty *QConnectorEnd::definingEnd() const
{
    // This is a read-only derived association end

    qWarning("QConnectorEnd::definingEnd: to be implemented (this is a derived associationend)");

    return 0; // change here to your derived return
}

void QConnectorEnd::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *>("QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QConnectorEnd) *> *");
    qRegisterMetaType<QConnectorEnd *>("QConnectorEnd *");
    qRegisterMetaType<const QSet<QConnectorEnd *> *>("const QSet<QConnectorEnd *> *");
    qRegisterMetaType<const QList<QConnectorEnd *> *>("const QList<QConnectorEnd *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QProperty) *>("QT_PREPEND_NAMESPACE_QTUML(QProperty) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QProperty) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QProperty) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QProperty) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QProperty) *> *");
    qRegisterMetaType<QProperty *>("QProperty *");
    qRegisterMetaType<const QSet<QProperty *> *>("const QSet<QProperty *> *");
    qRegisterMetaType<const QList<QProperty *> *>("const QList<QProperty *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QConnectableElement) *>("QT_PREPEND_NAMESPACE_QTUML(QConnectableElement) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnectableElement) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QConnectableElement) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QConnectableElement) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QConnectableElement) *> *");
    qRegisterMetaType<QConnectableElement *>("QConnectableElement *");
    qRegisterMetaType<const QSet<QConnectableElement *> *>("const QSet<QConnectableElement *> *");
    qRegisterMetaType<const QList<QConnectableElement *> *>("const QList<QConnectableElement *> *");

    QMultiplicityElement::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qconnectorend.cpp"

QT_END_NAMESPACE_QTUML

