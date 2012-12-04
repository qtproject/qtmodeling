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

#include "qqualifiervalue.h"
#include "qqualifiervalue_p.h"

#include <QtUml/QProperty>
#include <QtUml/QInputPin>

QT_BEGIN_NAMESPACE_QTUML

QQualifierValuePrivate::QQualifierValuePrivate() :
    value(0),
    qualifier(0)
{
}

QQualifierValuePrivate::~QQualifierValuePrivate()
{
}

/*!
    \class QQualifierValue

    \inmodule QtUml

    \brief A qualifier value is not an action. It is an element that identifies links. It gives a single qualifier within a link end data specification.
 */

QQualifierValue::QQualifierValue(QUmlObject *parent, QUmlObject *wrapper) :
    QElement(*new QQualifierValuePrivate, parent, wrapper)
{
}

QQualifierValue::QQualifierValue(QQualifierValuePrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QElement(dd, parent, wrapper)
{
}

QQualifierValue::~QQualifierValue()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QQualifierValue
// ---------------------------------------------------------------

/*!
    Input pin from which the specified value for the qualifier is taken.
 */
QInputPin *QQualifierValue::value() const
{
    // This is a read-write association end

    Q_D(const QQualifierValue);
    return d->value;
}

void QQualifierValue::setValue(QInputPin *value)
{
    // This is a read-write association end

    Q_D(QQualifierValue);
    if (d->value != value) {
        d->value = value;
    }
}

/*!
    Attribute representing the qualifier for which the value is to be specified.
 */
QProperty *QQualifierValue::qualifier() const
{
    // This is a read-write association end

    Q_D(const QQualifierValue);
    return d->qualifier;
}

void QQualifierValue::setQualifier(QProperty *qualifier)
{
    // This is a read-write association end

    Q_D(QQualifierValue);
    if (d->qualifier != qualifier) {
        d->qualifier = qualifier;
    }
}

#include "moc_qqualifiervalue.cpp"

QT_END_NAMESPACE_QTUML

