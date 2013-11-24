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
#include "qumlenumerationliteral.h"

#include "private/qumlenumerationliteralobject_p.h"

#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlDeployment>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlEnumeration>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlSlot>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlEnumerationLiteral

    \inmodule QtUml

    \brief An enumeration literal is a user-defined data value for an enumeration.
 */

/*!
    Creates a new QUmlEnumerationLiteral. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlEnumerationLiteral::QUmlEnumerationLiteral(bool createQModelingObject) :
    QUmlInstanceSpecification(false),
    _enumeration(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlEnumerationLiteralObject(this));
}

/*!
    Returns a deep-copied clone of the QUmlEnumerationLiteral.
*/
QModelingElement *QUmlEnumerationLiteral::clone() const
{
    QUmlEnumerationLiteral *c = new QUmlEnumerationLiteral;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    if (owningTemplateParameter())
        c->setOwningTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(owningTemplateParameter()->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(templateParameter()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlDeployment *element, deployments())
        c->addDeployment(dynamic_cast<QUmlDeployment *>(element->clone()));
    foreach (QUmlSlot *element, slots_())
        c->addSlot(dynamic_cast<QUmlSlot *>(element->clone()));
    if (specification())
        c->setSpecification(dynamic_cast<QUmlValueSpecification *>(specification()->clone()));
    if (enumeration())
        c->setEnumeration(dynamic_cast<QUmlEnumeration *>(enumeration()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The classifier of this EnumerationLiteral derived to be equal to its enumeration.

    \b {This is a read-only derived property.}

    \b {Redefined property(ies):} QUmlInstanceSpecification::classifiers().
 */
QUmlEnumeration *QUmlEnumerationLiteral::classifier() const
{
    // This is a read-only derived association end

    qWarning("QUmlEnumerationLiteral::classifier(): to be implemented (this is a derived association end)");

    return 0;
}

/*!
    Adjusts classifier to \a classifier.
 */
void QUmlEnumerationLiteral::setClassifier(QUmlEnumeration *classifier)
{
    // This is a read-only derived association end

    qWarning("QUmlEnumerationLiteral::setClassifier(): to be implemented (this is a derived association end)");
    Q_UNUSED(classifier);

    if (false /* <derivedexclusion-criteria> */) {
        // Adjust redefined properties        // QUmlInstanceSpecification::removeClassifier(/* <derived-code> */);

        // <derived-code>

        // Adjust redefined properties
        if (classifier) {
            QUmlInstanceSpecification::addClassifier(classifier);
        }
    }
}

/*!
    The Enumeration that this EnumerationLiteral is a member of.

    \b {Subsetted property(ies):} QUmlNamedElement::namespace_().

    \b {Opposite property(ies):} QUmlEnumeration::ownedLiterals().
 */
QUmlEnumeration *QUmlEnumerationLiteral::enumeration() const
{
    // This is a read-write association end

    return _enumeration;
}

/*!
    Adjusts enumeration to \a enumeration.
 */
void QUmlEnumerationLiteral::setEnumeration(QUmlEnumeration *enumeration)
{
    // This is a read-write association end

    if (_enumeration != enumeration) {
        // Adjust subsetted properties

        _enumeration = enumeration;
        if (enumeration && enumeration->asQModelingObject() && this->asQModelingObject())
            QObject::connect(enumeration->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setEnumeration()));

        // Adjust subsetted properties
        setNamespace(enumeration);
    }
}

QT_END_NAMESPACE

