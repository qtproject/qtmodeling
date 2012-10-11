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
#include "qaction_p.h"
#include "qelement_p.h"

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

void QLinkActionPrivate::addInputValue(const QInputPin *inputValue)
{
    this->inputValues->insert(const_cast<QInputPin *>(inputValue));

    // Adjust subsetted property(ies)
    addInput(inputValue);
}

void QLinkActionPrivate::removeInputValue(const QInputPin *inputValue)
{
    this->inputValues->remove(const_cast<QInputPin *>(inputValue));

    // Adjust subsetted property(ies)
    removeInput(inputValue);
}

void QLinkActionPrivate::addEndData(const QLinkEndData *endData)
{
    this->endData->insert(const_cast<QLinkEndData *>(endData));

    // Adjust subsetted property(ies)
    addOwnedElement(endData);
}

void QLinkActionPrivate::removeEndData(const QLinkEndData *endData)
{
    this->endData->remove(const_cast<QLinkEndData *>(endData));

    // Adjust subsetted property(ies)
    removeOwnedElement(endData);
}

/*!
    \class QLinkAction

    \inmodule QtUml

    \brief LinkAction is an abstract class for all link actions that identify their links by the objects at the ends of the links and by the qualifiers at ends of the links.
 */

QLinkAction::QLinkAction()
{
    d_umlptr = new QLinkActionPrivate;
}

QLinkAction::~QLinkAction()
{
}

/*!
    Pins taking end objects and qualifier values as input.
 */
const QSet<QInputPin *> *QLinkAction::inputValues() const
{
    QTUML_D(const QLinkAction);
    return d->inputValues;
}

void QLinkAction::addInputValue(const QInputPin *inputValue)
{
    QTUML_D(QLinkAction);
    d->addInputValue(const_cast<QInputPin *>(inputValue));
}

void QLinkAction::removeInputValue(const QInputPin *inputValue)
{
    QTUML_D(QLinkAction);
    d->removeInputValue(const_cast<QInputPin *>(inputValue));
}

/*!
    Data identifying one end of a link by the objects on its ends and qualifiers.
 */
const QSet<QLinkEndData *> *QLinkAction::endData() const
{
    QTUML_D(const QLinkAction);
    return d->endData;
}

void QLinkAction::addEndData(const QLinkEndData *endData)
{
    QTUML_D(QLinkAction);
    d->addEndData(const_cast<QLinkEndData *>(endData));
}

void QLinkAction::removeEndData(const QLinkEndData *endData)
{
    QTUML_D(QLinkAction);
    d->removeEndData(const_cast<QLinkEndData *>(endData));
}

/*!
    The association operates on LinkAction. It returns the association of the action.
 */
QAssociation *QLinkAction::association() const
{
    qWarning("QLinkAction::association: operation to be implemented");
}

QT_END_NAMESPACE_QTUML
