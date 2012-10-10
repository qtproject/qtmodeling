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

#include "qelement.h"
#include "qelement_p.h"

#include <QtUml/QComment>

QT_BEGIN_NAMESPACE_QTUML

QElementPrivate::QElementPrivate() :
    ownedElements(new QSet<QElement *>),
    owner(0),
    ownedComments(new QSet<QComment *>)
{
}

QElementPrivate::~QElementPrivate()
{
    delete ownedElements;
    delete ownedComments;
}

void QElementPrivate::addOwnedElement(const QElement *ownedElement)
{
    this->ownedElements->insert(const_cast<QElement *>(ownedElement));
}

void QElementPrivate::removeOwnedElement(const QElement *ownedElement)
{
    this->ownedElements->remove(const_cast<QElement *>(ownedElement));
}

void QElementPrivate::setOwner(const QElement *owner)
{
    this->owner = const_cast<QElement *>(owner);
}

void QElementPrivate::addOwnedComment(const QComment *ownedComment)
{
    this->ownedComments->insert(const_cast<QComment *>(ownedComment));

    // Adjust subsetted property(ies)
    addOwnedElement(ownedComment);
}

void QElementPrivate::removeOwnedComment(const QComment *ownedComment)
{
    this->ownedComments->remove(const_cast<QComment *>(ownedComment));

    // Adjust subsetted property(ies)
    removeOwnedElement(ownedComment);
}

/*!
    \class QElement

    \inmodule QtUml

    \brief An element is a constituent of a model. As such, it has the capability of owning other elements.
 */

QElement::QElement()
{
    d_umlptr = new QElementPrivate;
}

QElement::~QElement()
{
    delete d_umlptr;
}

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QElement::ownedElements() const
{
    Q_D(const QElement);
    return d->ownedElements;
}

/*!
    The Element that owns this element.
 */
QElement *QElement::owner() const
{
    Q_D(const QElement);
    return d->owner;
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QElement::ownedComments() const
{
    Q_D(const QElement);
    return d->ownedComments;
}

void QElement::addOwnedComment(const QComment *ownedComment)
{
    Q_D(QElement);
    d->addOwnedComment(const_cast<QComment *>(ownedComment));
}

void QElement::removeOwnedComment(const QComment *ownedComment)
{
    Q_D(QElement);
    d->removeOwnedComment(const_cast<QComment *>(ownedComment));
}

/*!
    The query allOwnedElements() gives all of the direct and indirect owned elements of an element.
 */
const QSet<QElement *> *QElement::allOwnedElements() const
{
    qWarning("QElement::allOwnedElements: operation to be implemented");
}

/*!
    The query mustBeOwned() indicates whether elements of this type must have an owner. Subclasses of Element that do not require an owner must override this operation.
 */
bool QElement::mustBeOwned() const
{
    qWarning("QElement::mustBeOwned: operation to be implemented");
}

QT_END_NAMESPACE_QTUML

