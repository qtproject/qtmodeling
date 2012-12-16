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

#include "qlinkaction.h"
#include "qlinkaction_p.h"

#include <QtUml/QLinkEndData>
#include <QtUml/QInputPin>
#include <QtUml/QAssociation>

QT_BEGIN_NAMESPACE_QTUML

QLinkActionPrivate::QLinkActionPrivate() :
    inputValues(new QSet<QInputPin *>),
    endData(new QSet<QLinkEndData *>)
{
}

QLinkActionPrivate::~QLinkActionPrivate()
{
    delete inputValues;
    delete endData;
}

/*!
    \class QLinkAction

    \inmodule QtUml

    \brief LinkAction is an abstract class for all link actions that identify their links by the objects at the ends of the links and by the qualifiers at ends of the links.
 */

QLinkAction::QLinkAction(QWrappedObject *parent, QWrappedObject *wrapper) :
    QAction(*new QLinkActionPrivate, parent, wrapper)
{
}

QLinkAction::QLinkAction(QLinkActionPrivate &dd, QWrappedObject *parent, QWrappedObject *wrapper) :
    QAction(dd, parent, wrapper)
{
}

QLinkAction::~QLinkAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QLinkAction
// ---------------------------------------------------------------

/*!
    Pins taking end objects and qualifier values as input.
 */
const QSet<QInputPin *> *QLinkAction::inputValues() const
{
    // This is a read-write association end

    Q_D(const QLinkAction);
    return d->inputValues;
}

void QLinkAction::addInputValue(QInputPin *inputValue)
{
    // This is a read-write association end

    Q_D(QLinkAction);
    if (!d->inputValues->contains(inputValue)) {
        d->inputValues->insert(inputValue);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->addInput(qwrappedobject_cast<QInputPin *>(inputValue));
    }
}

void QLinkAction::removeInputValue(QInputPin *inputValue)
{
    // This is a read-write association end

    Q_D(QLinkAction);
    if (d->inputValues->contains(inputValue)) {
        d->inputValues->remove(inputValue);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeInput(qwrappedobject_cast<QInputPin *>(inputValue));
    }
}

/*!
    Data identifying one end of a link by the objects on its ends and qualifiers.
 */
const QSet<QLinkEndData *> *QLinkAction::endData() const
{
    // This is a read-write association end

    Q_D(const QLinkAction);
    return d->endData;
}

void QLinkAction::addEndData(QLinkEndData *endData)
{
    // This is a read-write association end

    Q_D(QLinkAction);
    if (!d->endData->contains(endData)) {
        d->endData->insert(endData);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(endData));
    }
}

void QLinkAction::removeEndData(QLinkEndData *endData)
{
    // This is a read-write association end

    Q_D(QLinkAction);
    if (d->endData->contains(endData)) {
        d->endData->remove(endData);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(endData));
    }
}

/*!
    The association operates on LinkAction. It returns the association of the action.
 */
QAssociation *QLinkAction::association() const
{
    qWarning("QLinkAction::association: operation to be implemented");

    return 0; // change here to your derived return
}

void QLinkAction::registerMetaTypes() const
{
    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QLinkAction) *>("QT_PREPEND_NAMESPACE_QTUML(QLinkAction) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QLinkAction) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QLinkAction) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QLinkAction) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QLinkAction) *> *");
    qRegisterMetaType<QLinkAction *>("QLinkAction *");
    qRegisterMetaType<const QSet<QLinkAction *> *>("const QSet<QLinkAction *> *");
    qRegisterMetaType<const QList<QLinkAction *> *>("const QList<QLinkAction *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QLinkEndData) *>("QT_PREPEND_NAMESPACE_QTUML(QLinkEndData) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QLinkEndData) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QLinkEndData) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QLinkEndData) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QLinkEndData) *> *");
    qRegisterMetaType<QLinkEndData *>("QLinkEndData *");
    qRegisterMetaType<const QSet<QLinkEndData *> *>("const QSet<QLinkEndData *> *");
    qRegisterMetaType<const QList<QLinkEndData *> *>("const QList<QLinkEndData *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *>("QT_PREPEND_NAMESPACE_QTUML(QInputPin) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QInputPin) *> *");
    qRegisterMetaType<QInputPin *>("QInputPin *");
    qRegisterMetaType<const QSet<QInputPin *> *>("const QSet<QInputPin *> *");
    qRegisterMetaType<const QList<QInputPin *> *>("const QList<QInputPin *> *");


    qRegisterMetaType<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *>("QT_PREPEND_NAMESPACE_QTUML(QAssociation) *");
    qRegisterMetaType<const QSet<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *>("const QSet<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *");
    qRegisterMetaType<const QList<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *>("const QList<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *");
    qRegisterMetaType<QAssociation *>("QAssociation *");
    qRegisterMetaType<const QSet<QAssociation *> *>("const QSet<QAssociation *> *");
    qRegisterMetaType<const QList<QAssociation *> *>("const QList<QAssociation *> *");


    QAction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

#include "moc_qlinkaction.cpp"

QT_END_NAMESPACE_QTUML

