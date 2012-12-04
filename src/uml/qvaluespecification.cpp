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

#include "qvaluespecification.h"
#include "qvaluespecification_p.h"

#include <QtUml/QParameterableElement>

QT_BEGIN_NAMESPACE_QTUML

QValueSpecificationPrivate::QValueSpecificationPrivate()
{
}

QValueSpecificationPrivate::~QValueSpecificationPrivate()
{
}

/*!
    \class QValueSpecification

    \inmodule QtUml

    \brief ValueSpecification specializes ParameterableElement to specify that a value specification can be exposed as a formal template parameter, and provided as an actual parameter in a binding of a template.A value specification is the specification of a (possibly empty) set of instances, including both objects and data values.
 */

QValueSpecification::QValueSpecification(QUmlObject *parent, QUmlObject *wrapper) :
    QUmlObject(*new QValueSpecificationPrivate, parent, wrapper),
    _wrappedTypedElement(new QTypedElement(this, this)),
    _wrappedPackageableElement(new QPackageableElement(this, this))
{
}

QValueSpecification::QValueSpecification(QValueSpecificationPrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QUmlObject(dd, parent, wrapper),
    _wrappedTypedElement(new QTypedElement(this, this)),
    _wrappedPackageableElement(new QPackageableElement(this, this))
{
}

QValueSpecification::~QValueSpecification()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QValueSpecification::ownedElements() const
{
    return (qumlobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QValueSpecification::owner() const
{
    return (qumlobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QValueSpecification::ownedComments() const
{
    return (qumlobject_cast<const QElement *>(this))->ownedComments();
}

void QValueSpecification::addOwnedComment(QComment *ownedComment)
{
    (qumlobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QValueSpecification::removeOwnedComment(QComment *ownedComment)
{
    (qumlobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QValueSpecification::name() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->name();
}

void QValueSpecification::setName(QString name)
{
    (qumlobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QValueSpecification::qualifiedName() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QValueSpecification::nameExpression() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->nameExpression();
}

void QValueSpecification::setNameExpression(QStringExpression *nameExpression)
{
    (qumlobject_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QValueSpecification::namespace_() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QValueSpecification::clientDependencies() const
{
    return (qumlobject_cast<const QNamedElement *>(this))->clientDependencies();
}

void QValueSpecification::addClientDependency(QDependency *clientDependency)
{
    (qumlobject_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QValueSpecification::removeClientDependency(QDependency *clientDependency)
{
    (qumlobject_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QTypedElement
// ---------------------------------------------------------------

/*!
    This information is derived from the return result for this Operation.The type of the TypedElement.
 */
QType *QValueSpecification::type() const
{
    return (qumlobject_cast<const QTypedElement *>(this))->type();
}

void QValueSpecification::setType(QType *type)
{
    (qumlobject_cast<QTypedElement *>(this))->setType(type);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QParameterableElement
// ---------------------------------------------------------------

/*!
    The formal template parameter that owns this element.
 */
QTemplateParameter *QValueSpecification::owningTemplateParameter() const
{
    return (qumlobject_cast<const QParameterableElement *>(this))->owningTemplateParameter();
}

void QValueSpecification::setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter)
{
    (qumlobject_cast<QParameterableElement *>(this))->setOwningTemplateParameter(owningTemplateParameter);
}

/*!
    The template parameter that exposes this element as a formal parameter.
 */
QTemplateParameter *QValueSpecification::templateParameter() const
{
    return (qumlobject_cast<const QParameterableElement *>(this))->templateParameter();
}

void QValueSpecification::setTemplateParameter(QTemplateParameter *templateParameter)
{
    (qumlobject_cast<QParameterableElement *>(this))->setTemplateParameter(templateParameter);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QPackageableElement
// ---------------------------------------------------------------

/*!
    Indicates that packageable elements must always have a visibility, i.e., visibility is not optional.
 */
QtUml::VisibilityKind QValueSpecification::visibility() const
{
    return (qumlobject_cast<const QPackageableElement *>(this))->visibility();
}

void QValueSpecification::setVisibility(QtUml::VisibilityKind visibility)
{
    (qumlobject_cast<QPackageableElement *>(this))->setVisibility(visibility);
}

/*!
    The query booleanValue() gives a single Boolean value when one can be computed.
 */
bool QValueSpecification::booleanValue() const
{
    qWarning("QValueSpecification::booleanValue: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The query integerValue() gives a single Integer value when one can be computed.
 */
qint32 QValueSpecification::integerValue() const
{
    qWarning("QValueSpecification::integerValue: operation to be implemented");

    return qint32(); // change here to your derived return
}

/*!
    The query isCompatibleWith() determines if this parameterable element is compatible with the specified parameterable element. By default parameterable element P is compatible with parameterable element Q if the kind of P is the same or a subtype as the kind of Q. In addition, for ValueSpecification, the type must be conformant with the type of the specified parameterable element.
 */
bool QValueSpecification::isCompatibleWith(const QParameterableElement *p) const
{
    qWarning("QValueSpecification::isCompatibleWith: operation to be implemented");
    Q_UNUSED(p);

    return bool(); // change here to your derived return
}

/*!
    The query isComputable() determines whether a value specification can be computed in a model. This operation cannot be fully defined in OCL. A conforming implementation is expected to deliver true for this operation for all value specifications that it can compute, and to compute all of those for which the operation is true. A conforming implementation is expected to be able to compute the value of all literals.
 */
bool QValueSpecification::isComputable() const
{
    qWarning("QValueSpecification::isComputable: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The query isNull() returns true when it can be computed that the value is null.
 */
bool QValueSpecification::isNull() const
{
    qWarning("QValueSpecification::isNull: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The query realValue() gives a single Real value when one can be computed.
 */
qreal QValueSpecification::realValue() const
{
    qWarning("QValueSpecification::realValue: operation to be implemented");

    return qreal(); // change here to your derived return
}

/*!
    The query stringValue() gives a single String value when one can be computed.
 */
QString QValueSpecification::stringValue() const
{
    qWarning("QValueSpecification::stringValue: operation to be implemented");

    return QString(); // change here to your derived return
}

/*!
    The query unlimitedValue() gives a single UnlimitedNatural value when one can be computed.
 */
qint32 QValueSpecification::unlimitedValue() const
{
    qWarning("QValueSpecification::unlimitedValue: operation to be implemented");

    return qint32(); // change here to your derived return
}

#include "moc_qvaluespecification.cpp"

QT_END_NAMESPACE_QTUML
