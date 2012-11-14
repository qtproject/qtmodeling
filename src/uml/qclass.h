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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef QTUML_QCLASS_H
#define QTUML_QCLASS_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QEncapsulatedClassifier>
#include <QtUml/QBehavioredClassifier>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QReception;
class QNamedElement;
class QOperation;
class QClassifier;
class QExtension;
class QProperty;

class QClassPrivate;

class Q_UML_EXPORT QClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isAbstract READ isAbstract WRITE setAbstract)
    Q_PROPERTY(bool isActive READ isActive WRITE setActive)
    Q_PROPERTY(const QList<QClassifier *> * nestedClassifiers READ nestedClassifiers)
    Q_PROPERTY(const QSet<QReception *> * ownedReceptions READ ownedReceptions)
    Q_PROPERTY(const QSet<QExtension *> * extensions READ extensions STORED false)
    Q_PROPERTY(const QList<QOperation *> * ownedOperations READ ownedOperations)
    Q_PROPERTY(const QList<QProperty *> * ownedAttributes READ ownedAttributes)
    Q_PROPERTY(const QSet<QClass *> * superClasses READ superClasses STORED false)

    Q_DISABLE_COPY(QClass)
    Q_DECLARE_PRIVATE(QClass)

public:
    explicit QClass(QObject *parent = 0);
    virtual ~QClass();

    // Association ends from aggregated QElement
    const QSet<QElement *> *ownedElements() const;
    QElement *owner() const;
    const QSet<QComment *> *ownedComments() const;
    void addOwnedComment(QComment *ownedComment);
    void removeOwnedComment(QComment *ownedComment);

    // Attributes from aggregated QNamedElement
    QString name() const;
    void setName(QString name);
    QString qualifiedName() const;

    // Association ends from aggregated QNamedElement
    QStringExpression *nameExpression() const;
    void setNameExpression(QStringExpression *nameExpression);
    QNamespace *namespace_() const;
    const QSet<QDependency *> *clientDependencies() const;
    void addClientDependency(QDependency *clientDependency);
    void removeClientDependency(QDependency *clientDependency);

    // Association ends from aggregated QNamespace
    const QSet<QPackageImport *> *packageImports() const;
    void addPackageImport(QPackageImport *packageImport);
    void removePackageImport(QPackageImport *packageImport);
    const QSet<QNamedElement *> *members() const;
    const QSet<QPackageableElement *> *importedMembers() const;
    const QSet<QElementImport *> *elementImports() const;
    void addElementImport(QElementImport *elementImport);
    void removeElementImport(QElementImport *elementImport);
    const QSet<QConstraint *> *ownedRules() const;
    void addOwnedRule(QConstraint *ownedRule);
    void removeOwnedRule(QConstraint *ownedRule);
    const QSet<QNamedElement *> *ownedMembers() const;

    // Association ends from aggregated QParameterableElement
    QTemplateParameter *owningTemplateParameter() const;
    void setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter);

    // Attributes from aggregated QPackageableElement
    QtUml::VisibilityKind visibility() const;
    void setVisibility(QtUml::VisibilityKind visibility);

    // Association ends from aggregated QType
    QPackage *package() const;
    void setPackage(QPackage *package);

    // Attributes from aggregated QRedefinableElement
    bool isLeaf() const;
    void setLeaf(bool isLeaf);

    // Association ends from aggregated QRedefinableElement
    const QSet<QRedefinableElement *> *redefinedElements() const;
    const QSet<QClassifier *> *redefinitionContexts() const;

    // Association ends from aggregated QTemplateableElement
    const QSet<QTemplateBinding *> *templateBindings() const;
    void addTemplateBinding(QTemplateBinding *templateBinding);
    void removeTemplateBinding(QTemplateBinding *templateBinding);

    // Attributes from aggregated QClassifier
    bool isFinalSpecialization() const;
    void setFinalSpecialization(bool isFinalSpecialization);

    // Association ends from aggregated QClassifier
    const QSet<QUseCase *> *ownedUseCases() const;
    void addOwnedUseCase(QUseCase *ownedUseCase);
    void removeOwnedUseCase(QUseCase *ownedUseCase);
    const QSet<QGeneralizationSet *> *powertypeExtents() const;
    void addPowertypeExtent(QGeneralizationSet *powertypeExtent);
    void removePowertypeExtent(QGeneralizationSet *powertypeExtent);
    const QSet<QUseCase *> *useCases() const;
    void addUseCase(QUseCase *useCase);
    void removeUseCase(QUseCase *useCase);
    QClassifierTemplateParameter *templateParameter() const;
    void setTemplateParameter(QClassifierTemplateParameter *templateParameter);
    const QSet<QClassifier *> *redefinedClassifiers() const;
    void addRedefinedClassifier(QClassifier *redefinedClassifier);
    void removeRedefinedClassifier(QClassifier *redefinedClassifier);
    QRedefinableTemplateSignature *ownedTemplateSignature() const;
    void setOwnedTemplateSignature(QRedefinableTemplateSignature *ownedTemplateSignature);
    const QSet<QCollaborationUse *> *collaborationUses() const;
    void addCollaborationUse(QCollaborationUse *collaborationUse);
    void removeCollaborationUse(QCollaborationUse *collaborationUse);
    const QSet<QProperty *> *attributes() const;
    const QSet<QFeature *> *features() const;
    QCollaborationUse *representation() const;
    void setRepresentation(QCollaborationUse *representation);
    const QSet<QGeneralization *> *generalizations() const;
    void addGeneralization(QGeneralization *generalization);
    void removeGeneralization(QGeneralization *generalization);
    const QSet<QNamedElement *> *inheritedMembers() const;
    const QSet<QSubstitution *> *substitutions() const;
    void addSubstitution(QSubstitution *substitution);
    void removeSubstitution(QSubstitution *substitution);

    // Association ends from aggregated QStructuredClassifier
    const QSet<QConnectableElement *> *roles() const;
    const QSet<QProperty *> *parts() const;
    const QSet<QConnector *> *ownedConnectors() const;
    void addOwnedConnector(QConnector *ownedConnector);
    void removeOwnedConnector(QConnector *ownedConnector);

    // Association ends from aggregated QEncapsulatedClassifier
    const QSet<QPort *> *ownedPorts() const;

    // Association ends from aggregated QBehavioredClassifier
    const QSet<QBehavior *> *ownedBehaviors() const;
    void addOwnedBehavior(QBehavior *ownedBehavior);
    void removeOwnedBehavior(QBehavior *ownedBehavior);
    const QSet<QInterfaceRealization *> *interfaceRealizations() const;
    void addInterfaceRealization(QInterfaceRealization *interfaceRealization);
    void removeInterfaceRealization(QInterfaceRealization *interfaceRealization);
    QBehavior *classifierBehavior() const;
    void setClassifierBehavior(QBehavior *classifierBehavior);

    // Attributes from QClass
    bool isAbstract() const;
    void setAbstract(bool isAbstract);
    bool isActive() const;
    void setActive(bool isActive);

    // Association ends from QClass
    const QList<QClassifier *> *nestedClassifiers() const;
    void addNestedClassifier(QClassifier *nestedClassifier);
    void removeNestedClassifier(QClassifier *nestedClassifier);
    const QSet<QReception *> *ownedReceptions() const;
    void addOwnedReception(QReception *ownedReception);
    void removeOwnedReception(QReception *ownedReception);
    const QSet<QExtension *> *extensions() const;
    const QList<QOperation *> *ownedOperations() const;
    void addOwnedOperation(QOperation *ownedOperation);
    void removeOwnedOperation(QOperation *ownedOperation);
    const QList<QProperty *> *ownedAttributes() const;
    void addOwnedAttribute(QProperty *ownedAttribute);
    void removeOwnedAttribute(QProperty *ownedAttribute);
    const QSet<QClass *> *superClasses() const;
    void addSuperClass(QClass *superClass);
    void removeSuperClass(QClass *superClass);

    // Operations
    const QSet<QNamedElement *> *inherit(const QSet<QNamedElement *> *inhs) const;

    // Classes which access read-only opposite properties should be friend
    friend class QExtensionPrivate;

protected:
    explicit QClass(QClassPrivate &dd, QObject *parent = 0);

private:
    QEncapsulatedClassifier *_wrappedEncapsulatedClassifier;
    QBehavioredClassifier *_wrappedBehavioredClassifier;
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QClass) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QClass) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QClass) *> *)

QT_END_HEADER

#endif // QTUML_QCLASS_H

