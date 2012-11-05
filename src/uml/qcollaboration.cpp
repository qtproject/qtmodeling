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

#include "qcollaboration.h"
#include "qcollaboration_p.h"

#include <QtUml/QConnectableElement>

QT_BEGIN_NAMESPACE_QTUML

QCollaborationPrivate::QCollaborationPrivate() :
    collaborationRoles(new QSet<QConnectableElement *>)
{
}

QCollaborationPrivate::~QCollaborationPrivate()
{
    delete collaborationRoles;
}

/*!
    \class QCollaboration

    \inmodule QtUml

    \brief A collaboration use represents the application of the pattern described by a collaboration to a specific situation involving specific classes or instances playing the roles of the collaboration.
 */

QCollaboration::QCollaboration(QObject *parent) :
    QObject(*new QCollaborationPrivate, parent),
    _wrappedStructuredClassifier(new QStructuredClassifier(this)),
    _wrappedBehavioredClassifier(new QBehavioredClassifier(this))
{
    qRegisterMetaType<QCollaboration *>("QCollaboration *");
    qRegisterMetaType<const QSet<QCollaboration *> *>("const QSet<QCollaboration *> *");
    qRegisterMetaType<const QList<QCollaboration *> *>("const QList<QCollaboration *> *");
}

QCollaboration::QCollaboration(QCollaborationPrivate &dd, QObject *parent) :
    QObject(dd, parent),
    _wrappedStructuredClassifier(new QStructuredClassifier(this)),
    _wrappedBehavioredClassifier(new QBehavioredClassifier(this))
{
    qRegisterMetaType<QCollaboration *>("QCollaboration *");
    qRegisterMetaType<const QSet<QCollaboration *> *>("const QSet<QCollaboration *> *");
    qRegisterMetaType<const QList<QCollaboration *> *>("const QList<QCollaboration *> *");
}

QCollaboration::~QCollaboration()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QCollaboration::ownedElements() const
{
    return (qtuml_object_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QCollaboration::owner() const
{
    return (qtuml_object_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QCollaboration::ownedComments() const
{
    return (qtuml_object_cast<const QElement *>(this))->ownedComments();
}

void QCollaboration::addOwnedComment(QComment *ownedComment)
{
    (qtuml_object_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QCollaboration::removeOwnedComment(QComment *ownedComment)
{
    (qtuml_object_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QCollaboration::name() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->name();
}

void QCollaboration::setName(QString name)
{
    (qtuml_object_cast<QNamedElement *>(this))->setName(name);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QCollaboration::qualifiedName() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QCollaboration::nameExpression() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->nameExpression();
}

void QCollaboration::setNameExpression(QStringExpression *nameExpression)
{
    (qtuml_object_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QCollaboration::namespace_() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QCollaboration::clientDependencies() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->clientDependencies();
}

void QCollaboration::addClientDependency(QDependency *clientDependency)
{
    (qtuml_object_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QCollaboration::removeClientDependency(QDependency *clientDependency)
{
    (qtuml_object_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamespace
// ---------------------------------------------------------------

/*!
    References the PackageImports owned by the Namespace.
 */
const QSet<QPackageImport *> *QCollaboration::packageImports() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->packageImports();
}

void QCollaboration::addPackageImport(QPackageImport *packageImport)
{
    (qtuml_object_cast<QNamespace *>(this))->addPackageImport(packageImport);
}

void QCollaboration::removePackageImport(QPackageImport *packageImport)
{
    (qtuml_object_cast<QNamespace *>(this))->removePackageImport(packageImport);
}

/*!
    A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
 */
const QSet<QNamedElement *> *QCollaboration::members() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->members();
}

/*!
    References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
 */
const QSet<QPackageableElement *> *QCollaboration::importedMembers() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->importedMembers();
}

/*!
    References the ElementImports owned by the Namespace.
 */
const QSet<QElementImport *> *QCollaboration::elementImports() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->elementImports();
}

void QCollaboration::addElementImport(QElementImport *elementImport)
{
    (qtuml_object_cast<QNamespace *>(this))->addElementImport(elementImport);
}

void QCollaboration::removeElementImport(QElementImport *elementImport)
{
    (qtuml_object_cast<QNamespace *>(this))->removeElementImport(elementImport);
}

/*!
    Specifies a set of Constraints owned by this Namespace.
 */
const QSet<QConstraint *> *QCollaboration::ownedRules() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->ownedRules();
}

void QCollaboration::addOwnedRule(QConstraint *ownedRule)
{
    (qtuml_object_cast<QNamespace *>(this))->addOwnedRule(ownedRule);
}

void QCollaboration::removeOwnedRule(QConstraint *ownedRule)
{
    (qtuml_object_cast<QNamespace *>(this))->removeOwnedRule(ownedRule);
}

/*!
    A collection of NamedElements owned by the Namespace.
 */
const QSet<QNamedElement *> *QCollaboration::ownedMembers() const
{
    return (qtuml_object_cast<const QNamespace *>(this))->ownedMembers();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QParameterableElement
// ---------------------------------------------------------------

/*!
    The formal template parameter that owns this element.
 */
QTemplateParameter *QCollaboration::owningTemplateParameter() const
{
    return (qtuml_object_cast<const QParameterableElement *>(this))->owningTemplateParameter();
}

void QCollaboration::setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter)
{
    (qtuml_object_cast<QParameterableElement *>(this))->setOwningTemplateParameter(owningTemplateParameter);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QPackageableElement
// ---------------------------------------------------------------

/*!
    Indicates that packageable elements must always have a visibility, i.e., visibility is not optional.
 */
QtUml::VisibilityKind QCollaboration::visibility() const
{
    return (qtuml_object_cast<const QPackageableElement *>(this))->visibility();
}

void QCollaboration::setVisibility(QtUml::VisibilityKind visibility)
{
    (qtuml_object_cast<QPackageableElement *>(this))->setVisibility(visibility);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QType
// ---------------------------------------------------------------

/*!
    Specifies the owning package of this classifier, if any.
 */
QPackage *QCollaboration::package() const
{
    return (qtuml_object_cast<const QType *>(this))->package();
}

void QCollaboration::setPackage(QPackage *package)
{
    (qtuml_object_cast<QType *>(this))->setPackage(package);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement. Note that this property is preserved through package merge operations; that is, the capability to redefine a RedefinableElement (i.e., isLeaf=false) must be preserved in the resulting RedefinableElement of a package merge operation where a RedefinableElement with isLeaf=false is merged with a matching RedefinableElement with isLeaf=true: the resulting RedefinableElement will have isLeaf=false. Default value is false.
 */
bool QCollaboration::isLeaf() const
{
    return (qtuml_object_cast<const QRedefinableElement *>(this))->isLeaf();
}

void QCollaboration::setLeaf(bool isLeaf)
{
    (qtuml_object_cast<QRedefinableElement *>(this))->setLeaf(isLeaf);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    The redefinable element that is being redefined by this element.
 */
const QSet<QRedefinableElement *> *QCollaboration::redefinedElements() const
{
    return (qtuml_object_cast<const QRedefinableElement *>(this))->redefinedElements();
}

/*!
    References the contexts that this element may be redefined from.
 */
const QSet<QClassifier *> *QCollaboration::redefinitionContexts() const
{
    return (qtuml_object_cast<const QRedefinableElement *>(this))->redefinitionContexts();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QTemplateableElement
// ---------------------------------------------------------------

/*!
    The optional bindings from this element to templates.
 */
const QSet<QTemplateBinding *> *QCollaboration::templateBindings() const
{
    return (qtuml_object_cast<const QTemplateableElement *>(this))->templateBindings();
}

void QCollaboration::addTemplateBinding(QTemplateBinding *templateBinding)
{
    (qtuml_object_cast<QTemplateableElement *>(this))->addTemplateBinding(templateBinding);
}

void QCollaboration::removeTemplateBinding(QTemplateBinding *templateBinding)
{
    (qtuml_object_cast<QTemplateableElement *>(this))->removeTemplateBinding(templateBinding);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QClassifier
// ---------------------------------------------------------------

/*!
    If true, the Classifier does not provide a complete declaration and can typically not be instantiated. An abstract classifier is intended to be used by other classifiers e.g. as the target of general metarelationships or generalization relationships.
 */
bool QCollaboration::isAbstract() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->isAbstract();
}

void QCollaboration::setAbstract(bool isAbstract)
{
    (qtuml_object_cast<QClassifier *>(this))->setAbstract(isAbstract);
}

/*!
    If true, the Classifier cannot be specialized by generalization. Note that this property is preserved through package merge operations; that is, the capability to specialize a Classifier (i.e., isFinalSpecialization =false) must be preserved in the resulting Classifier of a package merge operation where a Classifier with isFinalSpecialization =false is merged with a matching Classifier with isFinalSpecialization =true: the resulting Classifier will have isFinalSpecialization =false.
 */
bool QCollaboration::isFinalSpecialization() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->isFinalSpecialization();
}

void QCollaboration::setFinalSpecialization(bool isFinalSpecialization)
{
    (qtuml_object_cast<QClassifier *>(this))->setFinalSpecialization(isFinalSpecialization);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QClassifier
// ---------------------------------------------------------------

/*!
    References the use cases owned by this classifier.
 */
const QSet<QUseCase *> *QCollaboration::ownedUseCases() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->ownedUseCases();
}

void QCollaboration::addOwnedUseCase(QUseCase *ownedUseCase)
{
    (qtuml_object_cast<QClassifier *>(this))->addOwnedUseCase(ownedUseCase);
}

void QCollaboration::removeOwnedUseCase(QUseCase *ownedUseCase)
{
    (qtuml_object_cast<QClassifier *>(this))->removeOwnedUseCase(ownedUseCase);
}

/*!
    Designates the GeneralizationSet of which the associated Classifier is a power type.
 */
const QSet<QGeneralizationSet *> *QCollaboration::powertypeExtents() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->powertypeExtents();
}

void QCollaboration::addPowertypeExtent(QGeneralizationSet *powertypeExtent)
{
    (qtuml_object_cast<QClassifier *>(this))->addPowertypeExtent(powertypeExtent);
}

void QCollaboration::removePowertypeExtent(QGeneralizationSet *powertypeExtent)
{
    (qtuml_object_cast<QClassifier *>(this))->removePowertypeExtent(powertypeExtent);
}

/*!
    The set of use cases for which this Classifier is the subject.
 */
const QSet<QUseCase *> *QCollaboration::useCases() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->useCases();
}

void QCollaboration::addUseCase(QUseCase *useCase)
{
    (qtuml_object_cast<QClassifier *>(this))->addUseCase(useCase);
}

void QCollaboration::removeUseCase(QUseCase *useCase)
{
    (qtuml_object_cast<QClassifier *>(this))->removeUseCase(useCase);
}

/*!
    The template parameter that exposes this element as a formal parameter.
 */
QClassifierTemplateParameter *QCollaboration::templateParameter() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->templateParameter();
}

void QCollaboration::setTemplateParameter(QClassifierTemplateParameter *templateParameter)
{
    (qtuml_object_cast<QClassifier *>(this))->setTemplateParameter(templateParameter);
}

/*!
    References the Classifiers that are redefined by this Classifier.
 */
const QSet<QClassifier *> *QCollaboration::redefinedClassifiers() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->redefinedClassifiers();
}

void QCollaboration::addRedefinedClassifier(QClassifier *redefinedClassifier)
{
    (qtuml_object_cast<QClassifier *>(this))->addRedefinedClassifier(redefinedClassifier);
}

void QCollaboration::removeRedefinedClassifier(QClassifier *redefinedClassifier)
{
    (qtuml_object_cast<QClassifier *>(this))->removeRedefinedClassifier(redefinedClassifier);
}

/*!
    The optional template signature specifying the formal template parameters.
 */
QRedefinableTemplateSignature *QCollaboration::ownedTemplateSignature() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->ownedTemplateSignature();
}

void QCollaboration::setOwnedTemplateSignature(QRedefinableTemplateSignature *ownedTemplateSignature)
{
    (qtuml_object_cast<QClassifier *>(this))->setOwnedTemplateSignature(ownedTemplateSignature);
}

/*!
    References the collaboration uses owned by the classifier.
 */
const QSet<QCollaborationUse *> *QCollaboration::collaborationUses() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->collaborationUses();
}

void QCollaboration::addCollaborationUse(QCollaborationUse *collaborationUse)
{
    (qtuml_object_cast<QClassifier *>(this))->addCollaborationUse(collaborationUse);
}

void QCollaboration::removeCollaborationUse(QCollaborationUse *collaborationUse)
{
    (qtuml_object_cast<QClassifier *>(this))->removeCollaborationUse(collaborationUse);
}

/*!
    Refers to all of the Properties that are direct (i.e. not inherited or imported) attributes of the classifier.
 */
const QSet<QProperty *> *QCollaboration::attributes() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->attributes();
}

/*!
    Specifies each feature defined in the classifier.Note that there may be members of the Classifier that are of the type Feature but are not included in this association, e.g. inherited features.
 */
const QSet<QFeature *> *QCollaboration::features() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->features();
}

/*!
    Specifies the general Classifiers for this Classifier.References the general classifier in the Generalization relationship.
 */
const QSet<QClassifier *> *QCollaboration::generals() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->generals();
}

void QCollaboration::addGeneral(QClassifier *general)
{
    (qtuml_object_cast<QClassifier *>(this))->addGeneral(general);
}

void QCollaboration::removeGeneral(QClassifier *general)
{
    (qtuml_object_cast<QClassifier *>(this))->removeGeneral(general);
}

/*!
    References a collaboration use which indicates the collaboration that represents this classifier.
 */
QCollaborationUse *QCollaboration::representation() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->representation();
}

void QCollaboration::setRepresentation(QCollaborationUse *representation)
{
    (qtuml_object_cast<QClassifier *>(this))->setRepresentation(representation);
}

/*!
    Specifies the Generalization relationships for this Classifier. These Generalizations navigaten to more general classifiers in the generalization hierarchy.
 */
const QSet<QGeneralization *> *QCollaboration::generalizations() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->generalizations();
}

void QCollaboration::addGeneralization(QGeneralization *generalization)
{
    (qtuml_object_cast<QClassifier *>(this))->addGeneralization(generalization);
}

void QCollaboration::removeGeneralization(QGeneralization *generalization)
{
    (qtuml_object_cast<QClassifier *>(this))->removeGeneralization(generalization);
}

/*!
    Specifies all elements inherited by this classifier from the general classifiers.
 */
const QSet<QNamedElement *> *QCollaboration::inheritedMembers() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->inheritedMembers();
}

/*!
    References the substitutions that are owned by this Classifier.
 */
const QSet<QSubstitution *> *QCollaboration::substitutions() const
{
    return (qtuml_object_cast<const QClassifier *>(this))->substitutions();
}

void QCollaboration::addSubstitution(QSubstitution *substitution)
{
    (qtuml_object_cast<QClassifier *>(this))->addSubstitution(substitution);
}

void QCollaboration::removeSubstitution(QSubstitution *substitution)
{
    (qtuml_object_cast<QClassifier *>(this))->removeSubstitution(substitution);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QStructuredClassifier
// ---------------------------------------------------------------

/*!
    References the roles that instances may play in this classifier.
 */
const QSet<QConnectableElement *> *QCollaboration::roles() const
{
    return (qtuml_object_cast<const QStructuredClassifier *>(this))->roles();
}

/*!
    References the properties owned by the classifier.
 */
const QList<QProperty *> *QCollaboration::ownedAttributes() const
{
    return (qtuml_object_cast<const QStructuredClassifier *>(this))->ownedAttributes();
}

void QCollaboration::addOwnedAttribute(QProperty *ownedAttribute)
{
    (qtuml_object_cast<QStructuredClassifier *>(this))->addOwnedAttribute(ownedAttribute);
}

void QCollaboration::removeOwnedAttribute(QProperty *ownedAttribute)
{
    (qtuml_object_cast<QStructuredClassifier *>(this))->removeOwnedAttribute(ownedAttribute);
}

/*!
    References the properties specifying instances that the classifier owns by composition. This association is derived, selecting those owned properties where isComposite is true.
 */
const QSet<QProperty *> *QCollaboration::parts() const
{
    return (qtuml_object_cast<const QStructuredClassifier *>(this))->parts();
}

/*!
    References the connectors owned by the classifier.
 */
const QSet<QConnector *> *QCollaboration::ownedConnectors() const
{
    return (qtuml_object_cast<const QStructuredClassifier *>(this))->ownedConnectors();
}

void QCollaboration::addOwnedConnector(QConnector *ownedConnector)
{
    (qtuml_object_cast<QStructuredClassifier *>(this))->addOwnedConnector(ownedConnector);
}

void QCollaboration::removeOwnedConnector(QConnector *ownedConnector)
{
    (qtuml_object_cast<QStructuredClassifier *>(this))->removeOwnedConnector(ownedConnector);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QBehavioredClassifier
// ---------------------------------------------------------------

/*!
    References behavior specifications owned by a classifier.
 */
const QSet<QBehavior *> *QCollaboration::ownedBehaviors() const
{
    return (qtuml_object_cast<const QBehavioredClassifier *>(this))->ownedBehaviors();
}

void QCollaboration::addOwnedBehavior(QBehavior *ownedBehavior)
{
    (qtuml_object_cast<QBehavioredClassifier *>(this))->addOwnedBehavior(ownedBehavior);
}

void QCollaboration::removeOwnedBehavior(QBehavior *ownedBehavior)
{
    (qtuml_object_cast<QBehavioredClassifier *>(this))->removeOwnedBehavior(ownedBehavior);
}

/*!
    The set of InterfaceRealizations owned by the BehavioredClassifier. Interface realizations reference the Interfaces of which the BehavioredClassifier is an implementation.
 */
const QSet<QInterfaceRealization *> *QCollaboration::interfaceRealizations() const
{
    return (qtuml_object_cast<const QBehavioredClassifier *>(this))->interfaceRealizations();
}

void QCollaboration::addInterfaceRealization(QInterfaceRealization *interfaceRealization)
{
    (qtuml_object_cast<QBehavioredClassifier *>(this))->addInterfaceRealization(interfaceRealization);
}

void QCollaboration::removeInterfaceRealization(QInterfaceRealization *interfaceRealization)
{
    (qtuml_object_cast<QBehavioredClassifier *>(this))->removeInterfaceRealization(interfaceRealization);
}

/*!
    A behavior specification that specifies the behavior of the classifier itself.
 */
QBehavior *QCollaboration::classifierBehavior() const
{
    return (qtuml_object_cast<const QBehavioredClassifier *>(this))->classifierBehavior();
}

void QCollaboration::setClassifierBehavior(QBehavior *classifierBehavior)
{
    (qtuml_object_cast<QBehavioredClassifier *>(this))->setClassifierBehavior(classifierBehavior);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QCollaboration
// ---------------------------------------------------------------

/*!
    References connectable elements (possibly owned by other classifiers) which represent roles that instances may play in this collaboration.
 */
const QSet<QConnectableElement *> *QCollaboration::collaborationRoles() const
{
    // This is a read-write association end

    Q_D(const QCollaboration);
    return d->collaborationRoles;
}

void QCollaboration::addCollaborationRole(QConnectableElement *collaborationRole)
{
    // This is a read-write association end

    Q_D(QCollaboration);
    if (!d->collaborationRoles->contains(collaborationRole)) {
        d->collaborationRoles->insert(collaborationRole);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QStructuredClassifierPrivate *>(d))->addRole(qtuml_object_cast<QConnectableElement *>(collaborationRole));
    }
}

void QCollaboration::removeCollaborationRole(QConnectableElement *collaborationRole)
{
    // This is a read-write association end

    Q_D(QCollaboration);
    if (d->collaborationRoles->contains(collaborationRole)) {
        d->collaborationRoles->remove(collaborationRole);

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QStructuredClassifierPrivate *>(d))->removeRole(qtuml_object_cast<QConnectableElement *>(collaborationRole));
    }
}

#include "moc_qcollaboration.cpp"

QT_END_NAMESPACE_QTUML

