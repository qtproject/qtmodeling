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

#include "qexpression.h"
#include "qexpression_p.h"
#include "qelement_p.h"


QT_BEGIN_NAMESPACE_QTUML

QExpressionPrivate::QExpressionPrivate() :
    operands(new QList<QValueSpecification *>)
{
}

QExpressionPrivate::~QExpressionPrivate()
{
    delete operands;
}

void QExpressionPrivate::setSymbol(QString symbol)
{
    this->symbol = symbol;
}

void QExpressionPrivate::addOperand(const QValueSpecification *operand)
{
    this->operands->append(const_cast<QValueSpecification *>(operand));

    // Adjust subsetted property(ies)
    addOwnedElement(operand);
}

void QExpressionPrivate::removeOperand(const QValueSpecification *operand)
{
    this->operands->removeAll(const_cast<QValueSpecification *>(operand));

    // Adjust subsetted property(ies)
    removeOwnedElement(operand);
}

/*!
    \class QExpression

    \inmodule QtUml

    \brief An expression is a structured tree of symbols that denotes a (possibly empty) set of values when evaluated in a context.An expression represents a node in an expression tree, which may be non-terminal or terminal. It defines a symbol, and has a possibly empty sequence of operands which are value specifications.
 */

QExpression::QExpression(QObject *parent)
    : QObject(parent)
{
    d_umlptr = new QExpressionPrivate;
}

QExpression::QExpression(bool createPimpl, QObject *parent)
    : QObject(parent)
{
    if (createPimpl)
        d_umlptr = new QExpressionPrivate;
}

QExpression::~QExpression()
{
}

/*!
    The symbol associated with the node in the expression tree.
 */
QString QExpression::symbol() const
{
    QTUML_D(const QExpression);
    return d->symbol;
}

void QExpression::setSymbol(QString symbol)
{
    QTUML_D(QExpression);
    d->setSymbol(symbol);
}

/*!
    Specifies a sequence of operands.
 */
const QList<QValueSpecification *> *QExpression::operands() const
{
    QTUML_D(const QExpression);
    return d->operands;
}

void QExpression::addOperand(const QValueSpecification *operand)
{
    QTUML_D(QExpression);
    d->addOperand(const_cast<QValueSpecification *>(operand));
}

void QExpression::removeOperand(const QValueSpecification *operand)
{
    QTUML_D(QExpression);
    d->removeOperand(const_cast<QValueSpecification *>(operand));
}

#include "moc_qexpression.cpp"

QT_END_NAMESPACE_QTUML
