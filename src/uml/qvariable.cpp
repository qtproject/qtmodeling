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

#include "qvariable.h"
#include "qvariable_p.h"

#include <QtUml/QActivity>
#include <QtUml/QStructuredActivityNode>
#include <QtUml/QAction>

QT_BEGIN_NAMESPACE_QTUML

QVariablePrivate::QVariablePrivate() :
    scope(0),
    activityScope(0)
{
}

QVariablePrivate::~QVariablePrivate()
{
}

/*!
    \class QVariable

    \inmodule QtUml

    \brief A variable is considered a connectable element.Variables are elements for passing data between actions indirectly. A local variable stores values shared by the actions within a structured activity group but not accessible outside it. The output of an action may be written to a variable and read for the input to a subsequent action, which is effectively an indirect data flow path. Because there is no predefined relationship between actions that read and write variables, these actions must be sequenced by control flows to prevent race conditions that may occur between actions that read or write the same variable.
 */

QVariable::QVariable(QtMof::QMofObject *parent, QtMof::QMofObject *wrapper) :
    QtMof::QMofObject(*new QVariablePrivate, parent, wrapper),
    _wrappedMultiplicityElement(new QMultiplicityElement(this, this)),
    _wrappedConnectableElement(new QConnectableElement(this, this))
{
}

QVariable::QVariable(QVariablePrivate &dd, QtMof::QMofObject *parent, QtMof::QMofObject *wrapper) :
    QtMof::QMofObject(dd, parent, wrapper),
    _wrappedMultiplicityElement(new QMultiplicityElement(this, this)),
    _wrappedConnectableElement(new QConnectableElement(this, this))
{
}

QVariable::~QVariable()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QVariable::ownedElements() const
{
    return (qmofobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QVariable::owner() const
{
    return (qmofobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QVariable::ownedComments() const
{
    return (qmofobject_cast<const QElement *>(this))->ownedComments();
}

void QVariable::addOwnedComment(QComment *ownedComment)
{
    (qmofobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QVariable::removeOwnedComment(QComment *ownedComment)
{
    (qmofobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QMultiplicityElement
// ---------------------------------------------------------------

/*!
    Specifies the upper bound of the multiplicity interval.
 */
qint32 QVariable::upper() const
{
    return (qmofobject_cast<const QMultiplicityElement *>(this))->upper();
}

void QVariable::setUpper(qint32 upper)
{
    (qmofobject_cast<QMultiplicityElement *>(this))->setUpper(upper);
}

/*!
    For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this element are unique.
 */
bool QVariable::isUnique() const
{
    return (qmofobject_cast<const QMultiplicityElement *>(this))->isUnique();
}

void QVariable::setUnique(bool isUnique)
{
    (qmofobject_cast<QMultiplicityElement *>(this))->setUnique(isUnique);
}

/*!
    For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this element are sequentially ordered.
 */
bool QVariable::isOrdered() const
{
    return (qmofobject_cast<const QMultiplicityElement *>(this))->isOrdered();
}

void QVariable::setOrdered(bool isOrdered)
{
    (qmofobject_cast<QMultiplicityElement *>(this))->setOrdered(isOrdered);
}

/*!
    Specifies the lower bound of the multiplicity interval.
 */
qint32 QVariable::lower() const
{
    return (qmofobject_cast<const QMultiplicityElement *>(this))->lower();
}

void QVariable::setLower(qint32 lower)
{
    (qmofobject_cast<QMultiplicityElement *>(this))->setLower(lower);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QMultiplicityElement
// ---------------------------------------------------------------

/*!
    The specification of the upper bound for this multiplicity.
 */
QValueSpecification *QVariable::upperValue() const
{
    return (qmofobject_cast<const QMultiplicityElement *>(this))->upperValue();
}

void QVariable::setUpperValue(QValueSpecification *upperValue)
{
    (qmofobject_cast<QMultiplicityElement *>(this))->setUpperValue(upperValue);
}

/*!
    The specification of the lower bound for this multiplicity.
 */
QValueSpecification *QVariable::lowerValue() const
{
    return (qmofobject_cast<const QMultiplicityElement *>(this))->lowerValue();
}

void QVariable::setLowerValue(QValueSpecification *lowerValue)
{
    (qmofobject_cast<QMultiplicityElement *>(this))->setLowerValue(lowerValue);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QVariable::name() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->name();
}

void QVariable::setName(QString name)
{
    (qmofobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.
 */
QtUml::VisibilityKind QVariable::visibility() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->visibility();
}

void QVariable::setVisibility(QtUml::VisibilityKind visibility)
{
    (qmofobject_cast<QNamedElement *>(this))->setVisibility(visibility);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QVariable::qualifiedName() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QVariable::nameExpression() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->nameExpression();
}

void QVariable::setNameExpression(QStringExpression *nameExpression)
{
    (qmofobject_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QVariable::namespace_() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QVariable::clientDependencies() const
{
    return (qmofobject_cast<const QNamedElement *>(this))->clientDependencies();
}

void QVariable::addClientDependency(QDependency *clientDependency)
{
    (qmofobject_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QVariable::removeClientDependency(QDependency *clientDependency)
{
    (qmofobject_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QTypedElement
// ---------------------------------------------------------------

/*!
    This information is derived from the return result for this Operation.The type of the TypedElement.
 */
QType *QVariable::type() const
{
    return (qmofobject_cast<const QTypedElement *>(this))->type();
}

void QVariable::setType(QType *type)
{
    (qmofobject_cast<QTypedElement *>(this))->setType(type);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QParameterableElement
// ---------------------------------------------------------------

/*!
    The formal template parameter that owns this element.
 */
QTemplateParameter *QVariable::owningTemplateParameter() const
{
    return (qmofobject_cast<const QParameterableElement *>(this))->owningTemplateParameter();
}

void QVariable::setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter)
{
    (qmofobject_cast<QParameterableElement *>(this))->setOwningTemplateParameter(owningTemplateParameter);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QConnectableElement
// ---------------------------------------------------------------

/*!
    Denotes a set of connector ends that attaches to this connectable element.
 */
const QList<QConnectorEnd *> *QVariable::ends() const
{
    return (qmofobject_cast<const QConnectableElement *>(this))->ends();
}

/*!
    The ConnectableElementTemplateParameter for this ConnectableElement parameter.
 */
QConnectableElementTemplateParameter *QVariable::templateParameter() const
{
    return (qmofobject_cast<const QConnectableElement *>(this))->templateParameter();
}

void QVariable::setTemplateParameter(QConnectableElementTemplateParameter *templateParameter)
{
    (qmofobject_cast<QConnectableElement *>(this))->setTemplateParameter(templateParameter);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QVariable
// ---------------------------------------------------------------

/*!
    A structured activity node that owns the variable.
 */
QStructuredActivityNode *QVariable::scope() const
{
    // This is a read-write association end

    Q_D(const QVariable);
    return d->scope;
}

void QVariable::setScope(QStructuredActivityNode *scope)
{
    // This is a read-write association end

    Q_D(QVariable);
    if (d->scope != scope) {
        // Adjust opposite property
        if (d->scope)
            d->scope->removeVariable(this);

        d->scope = scope;

        // Adjust subsetted property(ies)
        (qmofobject_cast<QNamedElementPrivate *>(d))->setNamespace_(qmofobject_cast<QNamespace *>(scope));

        // Adjust opposite property
        if (scope)
            scope->addVariable(this);
    }
}

/*!
    An activity that owns the variable.
 */
QActivity *QVariable::activityScope() const
{
    // This is a read-write association end

    Q_D(const QVariable);
    return d->activityScope;
}

void QVariable::setActivityScope(QActivity *activityScope)
{
    // This is a read-write association end

    Q_D(QVariable);
    if (d->activityScope != activityScope) {
        // Adjust opposite property
        if (d->activityScope)
            d->activityScope->removeVariable(this);

        d->activityScope = activityScope;

        // Adjust subsetted property(ies)
        (qmofobject_cast<QNamedElementPrivate *>(d))->setNamespace_(qmofobject_cast<QNamespace *>(activityScope));

        // Adjust opposite property
        if (activityScope)
            activityScope->addVariable(this);
    }
}

/*!
    The isAccessibleBy() operation is not defined in standard UML. Implementations should define it to specify which actions can access a variable.
 */
bool QVariable::isAccessibleBy(const QAction *a) const
{
    qWarning("QVariable::isAccessibleBy: operation to be implemented");
    Q_UNUSED(a);

    return bool(); // change here to your derived return
}

#include "moc_qvariable.cpp"

QT_END_NAMESPACE_QTUML

