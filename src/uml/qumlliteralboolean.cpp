/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "qumlliteralboolean.h"

#include "private/qumlliteralbooleanobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlType>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlLiteralBoolean

    \inmodule QtUml

    \brief A literal Boolean is a specification of a Boolean value.
 */

/*!
    Creates a new QUmlLiteralBoolean. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlLiteralBoolean::QUmlLiteralBoolean(bool createQModelingObject) :
    _value(false)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlLiteralBooleanObject(this));
}

/*!
    Destroys the QUmlLiteralBoolean.
 */
QUmlLiteralBoolean::~QUmlLiteralBoolean()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlLiteralBoolean.
*/
QModelingElement *QUmlLiteralBoolean::clone() const
{
    QUmlLiteralBoolean *c = new QUmlLiteralBoolean;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setValue(value());
    return c;
}

// OWNED ATTRIBUTES

/*!
    The specified Boolean value.
 */
bool QUmlLiteralBoolean::value() const
{
    // This is a read-write property

    return _value;
}

/*!
    Adjusts value to \a value.
 */
void QUmlLiteralBoolean::setValue(bool value)
{
    // This is a read-write property

    if (_value != value) {
        _value = value;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("value");
    }
}

// OPERATIONS

/*!
    The query booleanValue() gives the value.
 */
bool QUmlLiteralBoolean::booleanValue() const
{
    qWarning("QUmlLiteralBoolean::booleanValue(): to be implemented (operation)");

    return bool ();
}

/*!
    The query isComputable() is redefined to be true.
 */
bool QUmlLiteralBoolean::isComputable() const
{
    qWarning("QUmlLiteralBoolean::isComputable(): to be implemented (operation)");

    return bool ();
}

QT_END_NAMESPACE

