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
#include "qumlpartdecompositionobject_p.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlPartDecomposition>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlGate>
#include <QtUml/QUmlGeneralOrdering>
#include <QtUml/QUmlInteraction>
#include <QtUml/QUmlInteractionOperand>
#include <QtUml/QUmlLifeline>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

QUmlPartDecompositionObject::QUmlPartDecompositionObject(QUmlPartDecomposition *modelingElement)
{
    setProperty("modelingElement", QVariant::fromValue(static_cast<QModelingElement *>(modelingElement)));
    setGroupProperties();
    setPropertyData();
}

QUmlPartDecompositionObject::~QUmlPartDecompositionObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->deletingFromQModelingObject = true;
        delete qmodelingelementproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlPartDecompositionObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->ownedComments())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlPartDecompositionObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->ownedElements())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlPartDecompositionObject::owner() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->owner())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->owner()->asQModelingObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlPartDecompositionObject::clientDependencies() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->clientDependencies())
        set.insert(element->asQModelingObject());
    return set;
}

QString QUmlPartDecompositionObject::name() const
{
    return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->name();
}

QObject *QUmlPartDecompositionObject::nameExpression() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->nameExpression())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->nameExpression()->asQModelingObject();
}

QObject *QUmlPartDecompositionObject::namespace_() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->namespace_())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->namespace_()->asQModelingObject();
}

QString QUmlPartDecompositionObject::qualifiedName() const
{
    return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->qualifiedName();
}

QtUml::VisibilityKind QUmlPartDecompositionObject::visibility() const
{
    return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->visibility();
}

// OWNED ATTRIBUTES [InteractionFragment]

const QSet<QObject *> QUmlPartDecompositionObject::covered() const
{
    QSet<QObject *> set;
    foreach (QUmlLifeline *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->covered())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlPartDecompositionObject::enclosingInteraction() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->enclosingInteraction())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->enclosingInteraction()->asQModelingObject();
}

QObject *QUmlPartDecompositionObject::enclosingOperand() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->enclosingOperand())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->enclosingOperand()->asQModelingObject();
}

const QSet<QObject *> QUmlPartDecompositionObject::generalOrderings() const
{
    QSet<QObject *> set;
    foreach (QUmlGeneralOrdering *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->generalOrderings())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [InteractionUse]

const QSet<QObject *> QUmlPartDecompositionObject::actualGates() const
{
    QSet<QObject *> set;
    foreach (QUmlGate *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->actualGates())
        set.insert(element->asQModelingObject());
    return set;
}

const QList<QObject *> QUmlPartDecompositionObject::arguments() const
{
    QList<QObject *> list;
    foreach (QUmlValueSpecification *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->arguments())
        list.append(element->asQModelingObject());
    return list;
}

QObject *QUmlPartDecompositionObject::refersTo() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->refersTo())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->refersTo()->asQModelingObject();
}

QObject *QUmlPartDecompositionObject::returnValue() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->returnValue())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->returnValue()->asQModelingObject();
}

QObject *QUmlPartDecompositionObject::returnValueRecipient() const
{
    if (!qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->returnValueRecipient())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->returnValueRecipient()->asQModelingObject();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlPartDecompositionObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->allOwnedElements())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlPartDecompositionObject::mustBeOwned() const
{
    return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->mustBeOwned();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlPartDecompositionObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->allNamespaces())
        set.append(element->asQModelingObject());
    return set;
}

QSet<QObject *> QUmlPartDecompositionObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->allOwningPackages())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlPartDecompositionObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->isDistinguishableFrom(qmodelingelementproperty_cast<QUmlNamedElement *>(n), qmodelingelementproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlPartDecompositionObject::separator() const
{
    return qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->separator();
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlPartDecompositionObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlPartDecompositionObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlPartDecompositionObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlPartDecompositionObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlPartDecompositionObject::setOwner(QObject *owner)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setOwner(qmodelingelementproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlPartDecompositionObject::addClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlPartDecompositionObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlPartDecompositionObject::setName(QString name)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setName(name);
}

void QUmlPartDecompositionObject::setNameExpression(QObject *nameExpression)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setNameExpression(qmodelingelementproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlPartDecompositionObject::setNamespace(QObject *namespace_)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setNamespace(qmodelingelementproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlPartDecompositionObject::setQualifiedName(QString qualifiedName)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setQualifiedName(qualifiedName);
}

void QUmlPartDecompositionObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setVisibility(visibility);
}

// SLOTS FOR OWNED ATTRIBUTES [InteractionFragment]

void QUmlPartDecompositionObject::addCovered(QObject *covered)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addCovered(qmodelingelementproperty_cast<QUmlLifeline *>(covered));
}

void QUmlPartDecompositionObject::removeCovered(QObject *covered)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeCovered(qmodelingelementproperty_cast<QUmlLifeline *>(covered));
}

void QUmlPartDecompositionObject::setEnclosingInteraction(QObject *enclosingInteraction)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setEnclosingInteraction(qmodelingelementproperty_cast<QUmlInteraction *>(enclosingInteraction));
}

void QUmlPartDecompositionObject::setEnclosingOperand(QObject *enclosingOperand)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setEnclosingOperand(qmodelingelementproperty_cast<QUmlInteractionOperand *>(enclosingOperand));
}

void QUmlPartDecompositionObject::addGeneralOrdering(QObject *generalOrdering)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addGeneralOrdering(qmodelingelementproperty_cast<QUmlGeneralOrdering *>(generalOrdering));
}

void QUmlPartDecompositionObject::removeGeneralOrdering(QObject *generalOrdering)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeGeneralOrdering(qmodelingelementproperty_cast<QUmlGeneralOrdering *>(generalOrdering));
}

// SLOTS FOR OWNED ATTRIBUTES [InteractionUse]

void QUmlPartDecompositionObject::addActualGate(QObject *actualGate)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addActualGate(qmodelingelementproperty_cast<QUmlGate *>(actualGate));
}

void QUmlPartDecompositionObject::removeActualGate(QObject *actualGate)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeActualGate(qmodelingelementproperty_cast<QUmlGate *>(actualGate));
}

void QUmlPartDecompositionObject::addArgument(QObject *argument)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->addArgument(qmodelingelementproperty_cast<QUmlValueSpecification *>(argument));
}

void QUmlPartDecompositionObject::removeArgument(QObject *argument)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->removeArgument(qmodelingelementproperty_cast<QUmlValueSpecification *>(argument));
}

void QUmlPartDecompositionObject::setRefersTo(QObject *refersTo)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setRefersTo(qmodelingelementproperty_cast<QUmlInteraction *>(refersTo));
}

void QUmlPartDecompositionObject::setReturnValue(QObject *returnValue)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setReturnValue(qmodelingelementproperty_cast<QUmlValueSpecification *>(returnValue));
}

void QUmlPartDecompositionObject::setReturnValueRecipient(QObject *returnValueRecipient)
{
    qmodelingelementproperty_cast<QUmlPartDecomposition *>(this)->setReturnValueRecipient(qmodelingelementproperty_cast<QUmlProperty *>(returnValueRecipient));
}


void QUmlPartDecompositionObject::setGroupProperties()
{
    Q_D(QModelingObject);
    const QMetaObject *metaObject = this->metaObject();

    d->propertyGroups << QStringLiteral("QObject");
    d->groupProperties.insert(QStringLiteral("QObject"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("objectName"))));

    d->propertyGroups << QStringLiteral("QUmlElement");
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));

    d->propertyGroups << QStringLiteral("QUmlNamedElement");
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));

    d->propertyGroups << QStringLiteral("QUmlInteractionFragment");
    d->groupProperties.insert(QStringLiteral("QUmlInteractionFragment"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("covered"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionFragment"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("enclosingInteraction"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionFragment"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("enclosingOperand"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionFragment"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("generalOrderings"))));

    d->propertyGroups << QStringLiteral("QUmlInteractionUse");
    d->groupProperties.insert(QStringLiteral("QUmlInteractionUse"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("actualGates"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionUse"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("arguments"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionUse"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("refersTo"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionUse"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("returnValue"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionUse"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("returnValueRecipient"))));

    d->propertyGroups << QStringLiteral("QUmlPartDecomposition");
}

void QUmlPartDecompositionObject::setPropertyData()
{
}

QT_END_NAMESPACE

