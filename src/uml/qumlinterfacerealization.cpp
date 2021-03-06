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
#include "qumlinterfacerealization.h"

#include "private/qumlinterfacerealizationobject_p.h"

#include <QtUml/QUmlBehavioredClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterface>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOpaqueExpression>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlInterfaceRealization

    \inmodule QtUml

    \brief An interface realization is a specialized realization relationship between a classifier and an interface. This relationship signifies that the realizing classifier conforms to the contract specified by the interface.
 */

/*!
    Creates a new QUmlInterfaceRealization. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlInterfaceRealization::QUmlInterfaceRealization(bool createQModelingObject) :
    QUmlRealization(false),
    _contract(0),
    _implementingClassifier(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlInterfaceRealizationObject(this));
}

/*!
    Destroys the QUmlInterfaceRealization.
 */
QUmlInterfaceRealization::~QUmlInterfaceRealization()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlInterfaceRealization.
*/
QModelingElement *QUmlInterfaceRealization::clone() const
{
    QUmlInterfaceRealization *c = new QUmlInterfaceRealization;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    if (mapping())
        c->setMapping(dynamic_cast<QUmlOpaqueExpression *>(mapping()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    References the Interface specifying the conformance contract.

    \b {Subsetted property(ies):} QUmlDependency::suppliers().
 */
QUmlInterface *QUmlInterfaceRealization::contract() const
{
    // This is a read-write association end

    return _contract;
}

/*!
    Adjusts contract to \a contract.
 */
void QUmlInterfaceRealization::setContract(QUmlInterface *contract)
{
    // This is a read-write association end

    if (_contract != contract) {
        // Adjust subsetted properties
        removeSupplier(_contract);

        _contract = contract;
        if (contract && contract->asQModelingObject() && this->asQModelingObject())
            QObject::connect(contract->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setContract()));

        // Adjust subsetted properties
        if (contract) {
            addSupplier(contract);
        }
    }
}

/*!
    References the BehavioredClassifier that owns this Interfacerealization (i.e., the classifier that realizes the Interface to which it points).

    \b {Subsetted property(ies):} QUmlElement::owner(), QUmlDependency::clients().

    \b {Opposite property(ies):} QUmlBehavioredClassifier::interfaceRealizations().
 */
QUmlBehavioredClassifier *QUmlInterfaceRealization::implementingClassifier() const
{
    // This is a read-write association end

    return _implementingClassifier;
}

/*!
    Adjusts implementingClassifier to \a implementingClassifier.
 */
void QUmlInterfaceRealization::setImplementingClassifier(QUmlBehavioredClassifier *implementingClassifier)
{
    // This is a read-write association end

    if (_implementingClassifier != implementingClassifier) {
        // Adjust subsetted properties
        removeClient(_implementingClassifier);

        _implementingClassifier = implementingClassifier;
        if (implementingClassifier && implementingClassifier->asQModelingObject() && this->asQModelingObject())
            QObject::connect(implementingClassifier->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setImplementingClassifier()));

        // Adjust subsetted properties
        setOwner(implementingClassifier);
        if (implementingClassifier) {
            addClient(implementingClassifier);
        }
    }
}

QT_END_NAMESPACE

