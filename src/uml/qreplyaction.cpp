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

#include "qreplyaction.h"
#include "qreplyaction_p.h"

#include <QtUml/QTrigger>
#include <QtUml/QInputPin>

QT_BEGIN_NAMESPACE_QTUML

QReplyActionPrivate::QReplyActionPrivate() :
    replyToCall(0),
    returnInformation(0),
    replyValues(new QSet<QInputPin *>)
{
}

QReplyActionPrivate::~QReplyActionPrivate()
{
    delete replyValues;
}

/*!
    \class QReplyAction

    \inmodule QtUml

    \brief A reply action is an action that accepts a set of return values and a value containing return information produced by a previous accept call action. The reply action returns the values to the caller of the previous call, completing execution of the call.
 */

QReplyAction::QReplyAction(QWrappedObject *parent, QWrappedObject *wrapper) :
    QAction(*new QReplyActionPrivate, parent, wrapper)
{
}

QReplyAction::QReplyAction(QReplyActionPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QAction(dd, parent, wrapper)
{
}

QReplyAction::~QReplyAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QReplyAction
// ---------------------------------------------------------------

/*!
    The trigger specifying the operation whose call is being replied to.
 */
QTrigger *QReplyAction::replyToCall() const
{
    // This is a read-write association end

    Q_D(const QReplyAction);
    return d->replyToCall;
}

void QReplyAction::setReplyToCall(QTrigger *replyToCall)
{
    // This is a read-write association end

    Q_D(QReplyAction);
    if (d->replyToCall != replyToCall) {
        d->replyToCall = replyToCall;
    }
}

/*!
    A pin containing the return information value produced by an earlier AcceptCallAction.
 */
QInputPin *QReplyAction::returnInformation() const
{
    // This is a read-write association end

    Q_D(const QReplyAction);
    return d->returnInformation;
}

void QReplyAction::setReturnInformation(QInputPin *returnInformation)
{
    // This is a read-write association end

    Q_D(QReplyAction);
    if (d->returnInformation != returnInformation) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeInput(qwrappedobject_cast<QInputPin *>(d->returnInformation));

        d->returnInformation = returnInformation;

        // Adjust subsetted property(ies)
        if (returnInformation) {
            (qwrappedobject_cast<QActionPrivate *>(d))->addInput(qwrappedobject_cast<QInputPin *>(returnInformation));
        }
    }
}

/*!
    A list of pins containing the reply values of the operation. These values are returned to the caller.
 */
const QSet<QInputPin *> *QReplyAction::replyValues() const
{
    // This is a read-write association end

    Q_D(const QReplyAction);
    return d->replyValues;
}

void QReplyAction::addReplyValue(QInputPin *replyValue)
{
    // This is a read-write association end

    Q_D(QReplyAction);
    if (!d->replyValues->contains(replyValue)) {
        d->replyValues->insert(replyValue);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->addInput(qwrappedobject_cast<QInputPin *>(replyValue));
    }
}

void QReplyAction::removeReplyValue(QInputPin *replyValue)
{
    // This is a read-write association end

    Q_D(QReplyAction);
    if (d->replyValues->contains(replyValue)) {
        d->replyValues->remove(replyValue);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeInput(qwrappedobject_cast<QInputPin *>(replyValue));
    }
}

void QReplyAction::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QReplyAction) *>("QT_PREPEND_NAMESPACE_QTUML(QReplyAction) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QReplyAction) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QReplyAction) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QReplyAction) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QReplyAction) *> *");
    qRegisterMetaType<QReplyAction *>("QReplyAction *");
    qRegisterMetaType<const QSet<QReplyAction *> *>("const QSet<QReplyAction *> *");
    qRegisterMetaType<const QList<QReplyAction *> *>("const QList<QReplyAction *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QTrigger) *>("QT_PREPEND_NAMESPACE_QTUML(QTrigger) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QTrigger) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QTrigger) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QTrigger) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QTrigger) *> *");
    qRegisterMetaType<QTrigger *>("QTrigger *");
    qRegisterMetaType<const QSet<QTrigger *> *>("const QSet<QTrigger *> *");
    qRegisterMetaType<const QList<QTrigger *> *>("const QList<QTrigger *> *");

    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *>("QT_PREPEND_NAMESPACE_QTUML(QInputPin) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *");
    qRegisterMetaType<QInputPin *>("QInputPin *");
    qRegisterMetaType<const QSet<QInputPin *> *>("const QSet<QInputPin *> *");
    qRegisterMetaType<const QList<QInputPin *> *>("const QList<QInputPin *> *");

    QAction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qreplyaction.cpp"

QT_END_NAMESPACE_QTUML

