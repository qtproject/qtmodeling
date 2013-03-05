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

#include "qtestidentityaction.h"
#include "qtestidentityaction_p.h"

#include <QtUml/QInputPin>
#include <QtUml/QOutputPin>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

namespace QtUml
{

QTestIdentityActionPrivate::QTestIdentityActionPrivate() :
    second(0),
    result(0),
    first(0)
{
}

QTestIdentityActionPrivate::~QTestIdentityActionPrivate()
{
}

/*!
    \class QTestIdentityAction

    \inmodule QtUml

    \brief A test identity action is an action that tests if two values are identical objects.
 */

QTestIdentityAction::QTestIdentityAction(QWrappedObject *wrapper, QWrappedObject *parent) :
    QAction(*new QTestIdentityActionPrivate, wrapper, parent)
{
    setPropertyData();
}

QTestIdentityAction::QTestIdentityAction(QTestIdentityActionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QAction(dd, wrapper, parent)
{
    setPropertyData();
}

QTestIdentityAction::~QTestIdentityAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QTestIdentityAction
// ---------------------------------------------------------------

/*!
    Gives the pin on which an object is placed.
 */
QInputPin *QTestIdentityAction::second() const
{
    // This is a read-write association end

    Q_D(const QTestIdentityAction);
    return d->second;
}

void QTestIdentityAction::setSecond(QInputPin *second)
{
    // This is a read-write association end

    Q_D(QTestIdentityAction);
    if (d->second != second) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeInput(qwrappedobject_cast<QInputPin *>(d->second));

        d->second = second;

        // Adjust subsetted property(ies)
        if (second) {
            (qwrappedobject_cast<QActionPrivate *>(d))->addInput(qwrappedobject_cast<QInputPin *>(second));
        }
    }
}

/*!
    Tells whether the two input objects are identical.
 */
QOutputPin *QTestIdentityAction::result() const
{
    // This is a read-write association end

    Q_D(const QTestIdentityAction);
    return d->result;
}

void QTestIdentityAction::setResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QTestIdentityAction);
    if (d->result != result) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeOutput(qwrappedobject_cast<QOutputPin *>(d->result));

        d->result = result;

        // Adjust subsetted property(ies)
        if (result) {
            (qwrappedobject_cast<QActionPrivate *>(d))->addOutput(qwrappedobject_cast<QOutputPin *>(result));
        }
    }
}

/*!
    Gives the pin on which an object is placed.
 */
QInputPin *QTestIdentityAction::first() const
{
    // This is a read-write association end

    Q_D(const QTestIdentityAction);
    return d->first;
}

void QTestIdentityAction::setFirst(QInputPin *first)
{
    // This is a read-write association end

    Q_D(QTestIdentityAction);
    if (d->first != first) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeInput(qwrappedobject_cast<QInputPin *>(d->first));

        d->first = first;

        // Adjust subsetted property(ies)
        if (first) {
            (qwrappedobject_cast<QActionPrivate *>(d))->addInput(qwrappedobject_cast<QInputPin *>(first));
        }
    }
}

void QTestIdentityAction::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("second")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("second")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("second")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Gives the pin on which an object is placed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("second")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("second")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QAction::inputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("second")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("result")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("result")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("result")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Tells whether the two input objects are identical.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("result")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("result")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QAction::outputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("result")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("first")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("first")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("first")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Gives the pin on which an object is placed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("first")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("first")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QAction::inputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QTestIdentityAction")][QString::fromLatin1("first")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QAction::setPropertyData();
}

}

QT_END_NAMESPACE

#include "moc_qtestidentityaction.cpp"

