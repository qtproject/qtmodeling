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

#include "qtimeobservation.h"
#include "qtimeobservation_p.h"

#include <QtUml/QNamedElement>

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QTimeObservationPrivate::QTimeObservationPrivate() :
    firstEvent(true),
    event(0)
{
}

QTimeObservationPrivate::~QTimeObservationPrivate()
{
}

/*!
    \class QTimeObservation

    \inmodule QtUml

    \brief A time observation is a reference to a time instant during an execution. It points out the element in the model to observe and whether the observation is when this model element is entered or when it is exited.
 */

QTimeObservation::QTimeObservation(QWrappedObject *wrapper, QWrappedObject *parent) :
    QObservation(*new QTimeObservationPrivate, wrapper, parent)
{
    setPropertyData();
}

QTimeObservation::QTimeObservation(QTimeObservationPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QObservation(dd, wrapper, parent)
{
    setPropertyData();
}

QTimeObservation::~QTimeObservation()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QTimeObservation
// ---------------------------------------------------------------

/*!
    The value of firstEvent is related to event. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters event. If firstEvent is false, then the corresponding observation event is the time instant the execution exits event.
 */
bool QTimeObservation::firstEvent() const
{
    // This is a read-write attribute

    Q_D(const QTimeObservation);
    return d->firstEvent;
}

void QTimeObservation::setFirstEvent(bool firstEvent)
{
    // This is a read-write attribute

    Q_D(QTimeObservation);
    if (d->firstEvent != firstEvent) {
        d->firstEvent = firstEvent;
    }
    d->modifiedResettableProperties << QString::fromLatin1("firstEvent");
}

void QTimeObservation::unsetFirstEvent()
{
    setFirstEvent(true);
    Q_D(QTimeObservation);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("firstEvent"));
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QTimeObservation
// ---------------------------------------------------------------

/*!
    The observation is determined by the entering or exiting of the event element during execution.
 */
QNamedElement *QTimeObservation::event() const
{
    // This is a read-write association end

    Q_D(const QTimeObservation);
    return d->event;
}

void QTimeObservation::setEvent(QNamedElement *event)
{
    // This is a read-write association end

    Q_D(QTimeObservation);
    if (d->event != event) {
        d->event = event;
    }
}

void QTimeObservation::registerMetaTypes() const
{
    qRegisterMetaType<QNamedElement *>("QNamedElement *");
    qRegisterMetaType<QSet<QNamedElement *>>("QSet<QNamedElement *>");
    qRegisterMetaType<QList<QNamedElement *>>("QList<QNamedElement *>");

    QObservation::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QTimeObservation::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("firstEvent")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("firstEvent")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("firstEvent")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The value of firstEvent is related to event. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters event. If firstEvent is false, then the corresponding observation event is the time instant the execution exits event.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("firstEvent")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("firstEvent")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("firstEvent")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("event")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("event")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("event")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The observation is determined by the entering or exiting of the event element during execution.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("event")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("event")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QTimeObservation")][QString::fromLatin1("event")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QObservation::setPropertyData();
}

#include "moc_qtimeobservation.cpp"

QT_END_NAMESPACE_QTUML

