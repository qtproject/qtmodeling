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

#include "qvaluepin.h"
#include "qvaluepin_p.h"

#include <QtUml/QValueSpecification>

QT_BEGIN_NAMESPACE_QTUML

QValuePinPrivate::QValuePinPrivate() :
    value(0)
{
}

QValuePinPrivate::~QValuePinPrivate()
{
}

/*!
    \class QValuePin

    \inmodule QtUml

    \brief A value pin is an input pin that provides a value by evaluating a value specification.
 */

QValuePin::QValuePin(QUmlObject *parent, QUmlObject *wrapper) :
    QInputPin(*new QValuePinPrivate, parent, wrapper)
{
}

QValuePin::QValuePin(QValuePinPrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QInputPin(dd, parent, wrapper)
{
}

QValuePin::~QValuePin()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QValuePin
// ---------------------------------------------------------------

/*!
    Value that the pin will provide.
 */
QValueSpecification *QValuePin::value() const
{
    // This is a read-write association end

    Q_D(const QValuePin);
    return d->value;
}

void QValuePin::setValue(QValueSpecification *value)
{
    // This is a read-write association end

    Q_D(QValuePin);
    if (d->value != value) {
        // Adjust subsetted property(ies)
        (qumlobject_cast<QElementPrivate *>(d))->removeOwnedElement(qumlobject_cast<QElement *>(d->value));

        d->value = value;

        // Adjust subsetted property(ies)
        if (value) {
            (qumlobject_cast<QElementPrivate *>(d))->addOwnedElement(qumlobject_cast<QElement *>(value));
        }
    }
}

#include "moc_qvaluepin.cpp"

QT_END_NAMESPACE_QTUML

