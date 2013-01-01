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

#include "qprotocolstatemachine.h"
#include "qprotocolstatemachine_p.h"

#include <QtUml/QProtocolConformance>

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QProtocolStateMachinePrivate::QProtocolStateMachinePrivate()
{
}

QProtocolStateMachinePrivate::~QProtocolStateMachinePrivate()
{
}

/*!
    \class QProtocolStateMachine

    \inmodule QtUml

    \brief A protocol state machine is always defined in the context of a classifier. It specifies which operations of the classifier can be called in which state and under which condition, thus specifying the allowed call sequences on the classifier's operations. A protocol state machine presents the possible and permitted transitions on the instances of its context classifier, together with the operations which carry the transitions. In this manner, an instance lifecycle can be created for a classifier, by specifying the order in which the operations can be activated and the states through which an instance progresses during its existence.
 */

QProtocolStateMachine::QProtocolStateMachine(QWrappedObject *parent, QWrappedObject *wrapper) :
    QStateMachine(*new QProtocolStateMachinePrivate, parent, wrapper)
{
    setPropertyData();
}

QProtocolStateMachine::QProtocolStateMachine(QProtocolStateMachinePrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QStateMachine(dd, parent, wrapper)
{
    setPropertyData();
}

QProtocolStateMachine::~QProtocolStateMachine()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QProtocolStateMachine
// ---------------------------------------------------------------

/*!
    Conformance between protocol state machines.
 */
QSet<QProtocolConformance *> QProtocolStateMachine::conformance() const
{
    // This is a read-write association end

    Q_D(const QProtocolStateMachine);
    return d->conformance;
}

void QProtocolStateMachine::addConformance(QProtocolConformance *conformance)
{
    // This is a read-write association end

    Q_D(QProtocolStateMachine);
    if (!d->conformance.contains(conformance)) {
        d->conformance.insert(conformance);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(conformance));

        // Adjust opposite property
        conformance->setSpecificMachine(this);
    }
}

void QProtocolStateMachine::removeConformance(QProtocolConformance *conformance)
{
    // This is a read-write association end

    Q_D(QProtocolStateMachine);
    if (d->conformance.contains(conformance)) {
        d->conformance.remove(conformance);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(conformance));

        // Adjust opposite property
        conformance->setSpecificMachine(0);
    }
}

void QProtocolStateMachine::registerMetaTypes() const
{
    qRegisterMetaType<QProtocolConformance *>("QProtocolConformance *");
    qRegisterMetaType<QSet<QProtocolConformance *>>("QSet<QProtocolConformance *>");
    qRegisterMetaType<QList<QProtocolConformance *>>("QList<QProtocolConformance *>");

    QStateMachine::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QProtocolStateMachine::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QProtocolStateMachine")][QString::fromLatin1("conformance")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QProtocolStateMachine")][QString::fromLatin1("conformance")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QProtocolStateMachine")][QString::fromLatin1("conformance")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Conformance between protocol state machines.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QProtocolStateMachine")][QString::fromLatin1("conformance")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QProtocolStateMachine")][QString::fromLatin1("conformance")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::ownedElement");

    QStateMachine::setPropertyData();
}

#include "moc_qprotocolstatemachine.cpp"

QT_END_NAMESPACE_QTUML

