/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
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

#include "qmofexpression.h"
#include "qmofexpression_p.h"

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QMofExpressionPrivate::QMofExpressionPrivate()
{
}

QMofExpressionPrivate::~QMofExpressionPrivate()
{
}

/*!
    \class QMofExpression

    \inmodule QtMof

    \brief An expression represents a node in an expression tree, which may be non-terminal or terminal. It defines a symbol, and has a possibly empty sequence of operands which are value specifications.
 */

QMofExpression::QMofExpression(QWrappedObject *wrapper, QWrappedObject *parent) :
    QMofValueSpecification(*new QMofExpressionPrivate, wrapper, parent)
{
    setPropertyData();
}

QMofExpression::QMofExpression(QMofExpressionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QMofValueSpecification(dd, wrapper, parent)
{
    setPropertyData();
}

QMofExpression::~QMofExpression()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QMofExpression
// ---------------------------------------------------------------

/*!
    The symbol associated with the node in the expression tree.
 */
QString QMofExpression::symbol() const
{
    // This is a read-write attribute

    Q_D(const QMofExpression);
    return d->symbol;
}

void QMofExpression::setSymbol(QString symbol)
{
    // This is a read-write attribute

    Q_D(QMofExpression);
    if (d->symbol != symbol) {
        d->symbol = symbol;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QMofExpression
// ---------------------------------------------------------------

/*!
    Specifies a sequence of operands.
 */
QList<QMofValueSpecification *> QMofExpression::operands() const
{
    // This is a read-write association end

    Q_D(const QMofExpression);
    return d->operands;
}

void QMofExpression::addOperand(QMofValueSpecification *operand)
{
    // This is a read-write association end

    Q_D(QMofExpression);
    if (!d->operands.contains(operand)) {
        d->operands.append(operand);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QMofElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QMofElement *>(operand));
    }
}

void QMofExpression::removeOperand(QMofValueSpecification *operand)
{
    // This is a read-write association end

    Q_D(QMofExpression);
    if (d->operands.contains(operand)) {
        d->operands.removeAll(operand);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QMofElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QMofElement *>(operand));
    }
}

void QMofExpression::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("symbol")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("symbol")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("symbol")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The symbol associated with the node in the expression tree.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("symbol")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("symbol")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("symbol")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("operands")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("operands")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("operands")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Specifies a sequence of operands.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("operands")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("operands")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QMofElement::ownedElements");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QMofExpression")][QString::fromLatin1("operands")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QMofValueSpecification::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qmofexpression.cpp"

