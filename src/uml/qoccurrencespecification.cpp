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

#include "qoccurrencespecification.h"
#include "qoccurrencespecification_p.h"

#include <QtUml/QLifeline>
#include <QtUml/QGeneralOrdering>

QT_BEGIN_NAMESPACE_QTUML

QOccurrenceSpecificationPrivate::QOccurrenceSpecificationPrivate() :
    covered(0),
    toAfter(new QSet<QGeneralOrdering *>),
    toBefore(new QSet<QGeneralOrdering *>)
{
}

QOccurrenceSpecificationPrivate::~QOccurrenceSpecificationPrivate()
{
    delete toAfter;
    delete toBefore;
}

void QOccurrenceSpecificationPrivate::setCovered(QLifeline *covered)
{
    this->covered = covered;
}

void QOccurrenceSpecificationPrivate::addToAfter(QGeneralOrdering *toAfter)
{
    this->toAfter->insert(toAfter);
}

void QOccurrenceSpecificationPrivate::removeToAfter(QGeneralOrdering *toAfter)
{
    this->toAfter->remove(toAfter);
}

void QOccurrenceSpecificationPrivate::addToBefore(QGeneralOrdering *toBefore)
{
    this->toBefore->insert(toBefore);
}

void QOccurrenceSpecificationPrivate::removeToBefore(QGeneralOrdering *toBefore)
{
    this->toBefore->remove(toBefore);
}

/*!
    \class QOccurrenceSpecification

    \inmodule QtUml

    \brief An occurrence specification is the basic semantic unit of interactions. The sequences of occurrences specified by them are the meanings of interactions.
 */

QOccurrenceSpecification::QOccurrenceSpecification(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QOccurrenceSpecificationPrivate;
}

QOccurrenceSpecification::QOccurrenceSpecification(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QOccurrenceSpecificationPrivate;
}

QOccurrenceSpecification::~QOccurrenceSpecification()
{
}

/*!
    References the Lifeline on which the OccurrenceSpecification appears.
 */
QLifeline *QOccurrenceSpecification::covered() const
{
    QTUML_D(const QOccurrenceSpecification);
    return d->covered;
}

void QOccurrenceSpecification::setCovered(QLifeline *covered)
{
    QTUML_D(QOccurrenceSpecification);
    if (d->covered != covered) {
        d->setCovered(covered);
    }
}

/*!
    References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification
 */
const QSet<QGeneralOrdering *> *QOccurrenceSpecification::toAfter() const
{
    QTUML_D(const QOccurrenceSpecification);
    return d->toAfter;
}

void QOccurrenceSpecification::addToAfter(QGeneralOrdering *toAfter)
{
    QTUML_D(QOccurrenceSpecification);
    if (!d->toAfter->contains(toAfter)) {
        d->addToAfter(toAfter);

        // Adjust opposite property
        toAfter->setBefore(this);
    }
}

void QOccurrenceSpecification::removeToAfter(QGeneralOrdering *toAfter)
{
    QTUML_D(QOccurrenceSpecification);
    if (d->toAfter->contains(toAfter)) {
        d->removeToAfter(toAfter);

        // Adjust opposite property
        toAfter->setBefore(0);
    }
}

/*!
    References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification
 */
const QSet<QGeneralOrdering *> *QOccurrenceSpecification::toBefore() const
{
    QTUML_D(const QOccurrenceSpecification);
    return d->toBefore;
}

void QOccurrenceSpecification::addToBefore(QGeneralOrdering *toBefore)
{
    QTUML_D(QOccurrenceSpecification);
    if (!d->toBefore->contains(toBefore)) {
        d->addToBefore(toBefore);

        // Adjust opposite property
        toBefore->setAfter(this);
    }
}

void QOccurrenceSpecification::removeToBefore(QGeneralOrdering *toBefore)
{
    QTUML_D(QOccurrenceSpecification);
    if (d->toBefore->contains(toBefore)) {
        d->removeToBefore(toBefore);

        // Adjust opposite property
        toBefore->setAfter(0);
    }
}

#include "moc_qoccurrencespecification.cpp"

QT_END_NAMESPACE_QTUML

