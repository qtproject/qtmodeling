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

#include "qunmarshallaction.h"
#include "qunmarshallaction_p.h"
#include "qaction_p.h"
#include "qaction_p.h"

#include <QtUml/QInputPin>
#include <QtUml/QOutputPin>
#include <QtUml/QClassifier>

QT_BEGIN_NAMESPACE_QTUML

QUnmarshallActionPrivate::QUnmarshallActionPrivate() :
    object(0),
    results(new QSet<QOutputPin *>),
    unmarshallType(0)
{
}

QUnmarshallActionPrivate::~QUnmarshallActionPrivate()
{
    delete results;
}

void QUnmarshallActionPrivate::setObject(const QInputPin *object)
{
    // Adjust subsetted property(ies)
    removeInput(this->object);

    this->object = const_cast<QInputPin *>(object);

    // Adjust subsetted property(ies)
    addInput(object);
}

void QUnmarshallActionPrivate::addResult(const QOutputPin *result)
{
    this->results->insert(const_cast<QOutputPin *>(result));

    // Adjust subsetted property(ies)
    addOutput(result);
}

void QUnmarshallActionPrivate::removeResult(const QOutputPin *result)
{
    this->results->remove(const_cast<QOutputPin *>(result));

    // Adjust subsetted property(ies)
    removeOutput(result);
}

void QUnmarshallActionPrivate::setUnmarshallType(const QClassifier *unmarshallType)
{
    this->unmarshallType = const_cast<QClassifier *>(unmarshallType);
}

/*!
    \class QUnmarshallAction

    \inmodule QtUml

    \brief An unmarshall action is an action that breaks an object of a known type into outputs each of which is equal to a value from a structural feature of the object.
 */

QUnmarshallAction::QUnmarshallAction(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QUnmarshallActionPrivate;
}

QUnmarshallAction::QUnmarshallAction(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QUnmarshallActionPrivate;
}

QUnmarshallAction::~QUnmarshallAction()
{
}

/*!
    The object to be unmarshalled.
 */
QInputPin *QUnmarshallAction::object() const
{
    QTUML_D(const QUnmarshallAction);
    return d->object;
}

void QUnmarshallAction::setObject(const QInputPin *object)
{
    QTUML_D(QUnmarshallAction);
    d->setObject(const_cast<QInputPin *>(object));
}

/*!
    The values of the structural features of the input object.
 */
const QSet<QOutputPin *> *QUnmarshallAction::results() const
{
    QTUML_D(const QUnmarshallAction);
    return d->results;
}

void QUnmarshallAction::addResult(const QOutputPin *result)
{
    QTUML_D(QUnmarshallAction);
    d->addResult(const_cast<QOutputPin *>(result));
}

void QUnmarshallAction::removeResult(const QOutputPin *result)
{
    QTUML_D(QUnmarshallAction);
    d->removeResult(const_cast<QOutputPin *>(result));
}

/*!
    The type of the object to be unmarshalled.
 */
QClassifier *QUnmarshallAction::unmarshallType() const
{
    QTUML_D(const QUnmarshallAction);
    return d->unmarshallType;
}

void QUnmarshallAction::setUnmarshallType(const QClassifier *unmarshallType)
{
    QTUML_D(QUnmarshallAction);
    d->setUnmarshallType(const_cast<QClassifier *>(unmarshallType));
}

#include "moc_qunmarshallaction.cpp"

QT_END_NAMESPACE_QTUML
