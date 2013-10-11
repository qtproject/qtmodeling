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
#include "qumlinteractionconstraintobject_p.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlInteractionConstraint>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

QUmlInteractionConstraintObject::QUmlInteractionConstraintObject(QUmlInteractionConstraint *modelingElement)
{
    setProperty("modelingElement", QVariant::fromValue(static_cast<QModelingElement *>(modelingElement)));
    setGroupProperties();
    setPropertyData();
}

QUmlInteractionConstraintObject::~QUmlInteractionConstraintObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->deletingFromQModelingObject = true;
        delete qmodelingelementproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlInteractionConstraintObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->ownedComments())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlInteractionConstraintObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->ownedElements())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlInteractionConstraintObject::owner() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->owner())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->owner()->asQModelingObject();
}

// OWNED ATTRIBUTES [ParameterableElement]

QObject *QUmlInteractionConstraintObject::owningTemplateParameter() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->owningTemplateParameter())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->owningTemplateParameter()->asQModelingObject();
}

QObject *QUmlInteractionConstraintObject::templateParameter() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->templateParameter())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->templateParameter()->asQModelingObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlInteractionConstraintObject::clientDependencies() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->clientDependencies())
        set.insert(element->asQModelingObject());
    return set;
}

QString QUmlInteractionConstraintObject::name() const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->name();
}

QObject *QUmlInteractionConstraintObject::nameExpression() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->nameExpression())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->nameExpression()->asQModelingObject();
}

QObject *QUmlInteractionConstraintObject::namespace_() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->namespace_())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->namespace_()->asQModelingObject();
}

QString QUmlInteractionConstraintObject::qualifiedName() const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->qualifiedName();
}

// OWNED ATTRIBUTES [PackageableElement]

QtUml::VisibilityKind QUmlInteractionConstraintObject::visibility() const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->visibility();
}

// OWNED ATTRIBUTES [Constraint]

const QList<QObject *> QUmlInteractionConstraintObject::constrainedElements() const
{
    QList<QObject *> list;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->constrainedElements())
        list.append(element->asQModelingObject());
    return list;
}

QObject *QUmlInteractionConstraintObject::context() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->context())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->context()->asQModelingObject();
}

QObject *QUmlInteractionConstraintObject::specification() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->specification())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->specification()->asQModelingObject();
}

// OWNED ATTRIBUTES [InteractionConstraint]

QObject *QUmlInteractionConstraintObject::maxint() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->maxint())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->maxint()->asQModelingObject();
}

QObject *QUmlInteractionConstraintObject::minint() const
{
    if (!qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->minint())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->minint()->asQModelingObject();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlInteractionConstraintObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->allOwnedElements())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlInteractionConstraintObject::mustBeOwned() const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->mustBeOwned();
}

// OPERATIONS [ParameterableElement]

bool QUmlInteractionConstraintObject::isCompatibleWith(QObject *p) const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->isCompatibleWith(qmodelingelementproperty_cast<QUmlParameterableElement *>(p));
}

bool QUmlInteractionConstraintObject::isTemplateParameter() const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->isTemplateParameter();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlInteractionConstraintObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->allNamespaces())
        set.append(element->asQModelingObject());
    return set;
}

QSet<QObject *> QUmlInteractionConstraintObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->allOwningPackages())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlInteractionConstraintObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->isDistinguishableFrom(qmodelingelementproperty_cast<QUmlNamedElement *>(n), qmodelingelementproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlInteractionConstraintObject::separator() const
{
    return qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->separator();
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlInteractionConstraintObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->addOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlInteractionConstraintObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->removeOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlInteractionConstraintObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->addOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlInteractionConstraintObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->removeOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlInteractionConstraintObject::setOwner(QObject *owner)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setOwner(qmodelingelementproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [ParameterableElement]

void QUmlInteractionConstraintObject::setOwningTemplateParameter(QObject *owningTemplateParameter)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setOwningTemplateParameter(qmodelingelementproperty_cast<QUmlTemplateParameter *>(owningTemplateParameter));
}

void QUmlInteractionConstraintObject::setTemplateParameter(QObject *templateParameter)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setTemplateParameter(qmodelingelementproperty_cast<QUmlTemplateParameter *>(templateParameter));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlInteractionConstraintObject::addClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->addClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlInteractionConstraintObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->removeClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlInteractionConstraintObject::setName(QString name)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setName(name);
}

void QUmlInteractionConstraintObject::setNameExpression(QObject *nameExpression)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setNameExpression(qmodelingelementproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlInteractionConstraintObject::setNamespace(QObject *namespace_)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setNamespace(qmodelingelementproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlInteractionConstraintObject::setQualifiedName(QString qualifiedName)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setQualifiedName(qualifiedName);
}
// SLOTS FOR OWNED ATTRIBUTES [PackageableElement]

void QUmlInteractionConstraintObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setVisibility(visibility);
}

void QUmlInteractionConstraintObject::unsetVisibility()
{
    Q_D(QModelingObject);
    d->modifiedResettableProperties.removeAll(QStringLiteral("visibility"));
}

// SLOTS FOR OWNED ATTRIBUTES [Constraint]

void QUmlInteractionConstraintObject::addConstrainedElement(QObject *constrainedElement)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->addConstrainedElement(qmodelingelementproperty_cast<QUmlElement *>(constrainedElement));
}

void QUmlInteractionConstraintObject::removeConstrainedElement(QObject *constrainedElement)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->removeConstrainedElement(qmodelingelementproperty_cast<QUmlElement *>(constrainedElement));
}

void QUmlInteractionConstraintObject::setContext(QObject *context)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setContext(qmodelingelementproperty_cast<QUmlNamespace *>(context));
}

void QUmlInteractionConstraintObject::setSpecification(QObject *specification)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setSpecification(qmodelingelementproperty_cast<QUmlValueSpecification *>(specification));
}

// SLOTS FOR OWNED ATTRIBUTES [InteractionConstraint]

void QUmlInteractionConstraintObject::setMaxint(QObject *maxint)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setMaxint(qmodelingelementproperty_cast<QUmlValueSpecification *>(maxint));
}

void QUmlInteractionConstraintObject::setMinint(QObject *minint)
{
    qmodelingelementproperty_cast<QUmlInteractionConstraint *>(this)->setMinint(qmodelingelementproperty_cast<QUmlValueSpecification *>(minint));
}


void QUmlInteractionConstraintObject::setGroupProperties()
{
    Q_D(QModelingObject);
    const QMetaObject *metaObject = this->metaObject();

    d->propertyGroups << QStringLiteral("QObject");
    d->groupProperties.insert(QStringLiteral("QObject"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("objectName"))));

    d->propertyGroups << QStringLiteral("QUmlElement");
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));

    d->propertyGroups << QStringLiteral("QUmlParameterableElement");
    d->groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owningTemplateParameter"))));
    d->groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));

    d->propertyGroups << QStringLiteral("QUmlNamedElement");
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));

    d->propertyGroups << QStringLiteral("QUmlPackageableElement");
    d->groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));

    d->propertyGroups << QStringLiteral("QUmlConstraint");
    d->groupProperties.insert(QStringLiteral("QUmlConstraint"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("constrainedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlConstraint"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("context"))));
    d->groupProperties.insert(QStringLiteral("QUmlConstraint"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("specification"))));

    d->propertyGroups << QStringLiteral("QUmlInteractionConstraint");
    d->groupProperties.insert(QStringLiteral("QUmlInteractionConstraint"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("maxint"))));
    d->groupProperties.insert(QStringLiteral("QUmlInteractionConstraint"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("minint"))));
}

void QUmlInteractionConstraintObject::setPropertyData()
{
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, AggregationRole, QStringLiteral("composite"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, PropertyClassRole, QStringLiteral("QUmlInteractionConstraint"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, DocumentationRole, QStringLiteral("The maximum number of iterations of a loop"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, SubsettedPropertiesRole, QStringLiteral("Element-ownedElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, maxint, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, AggregationRole, QStringLiteral("composite"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, PropertyClassRole, QStringLiteral("QUmlInteractionConstraint"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, DocumentationRole, QStringLiteral("The minimum number of iterations of a loop"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, SubsettedPropertiesRole, QStringLiteral("Element-ownedElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlInteractionConstraint, minint, OppositeEndRole, QStringLiteral(""));

}

QT_END_NAMESPACE

