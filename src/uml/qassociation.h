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
#ifndef QTUML_QASSOCIATION_H
#define QTUML_QASSOCIATION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QClassifier>
#include <QtUml/QRelationship>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QType;
class QProperty;

class QAssociationPrivate;

class Q_UML_EXPORT QAssociation : public QObject
{
    Q_OBJECT

    // From aggregated QElement
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)

    // From aggregated QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(const QSet<QDependency *> * clientDependencies READ clientDependencies)

    // From aggregated QNamespace
    Q_PROPERTY(const QSet<QPackageImport *> * packageImports READ packageImports)
    Q_PROPERTY(const QSet<QNamedElement *> * members READ members)
    Q_PROPERTY(const QSet<QPackageableElement *> * importedMembers READ importedMembers)
    Q_PROPERTY(const QSet<QElementImport *> * elementImports READ elementImports)
    Q_PROPERTY(const QSet<QConstraint *> * ownedRules READ ownedRules)
    Q_PROPERTY(const QSet<QNamedElement *> * ownedMembers READ ownedMembers)

    // From aggregated QParameterableElement
    Q_PROPERTY(QTemplateParameter * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter)

    // From aggregated QPackageableElement
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)

    // From aggregated QType
    Q_PROPERTY(QPackage * package READ package WRITE setPackage)

    // From aggregated QRedefinableElement
    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf)
    Q_PROPERTY(const QSet<QRedefinableElement *> * redefinedElements READ redefinedElements)
    Q_PROPERTY(const QSet<QClassifier *> * redefinitionContexts READ redefinitionContexts)

    // From aggregated QTemplateableElement
    Q_PROPERTY(const QSet<QTemplateBinding *> * templateBindings READ templateBindings)

    // From aggregated QClassifier
    Q_PROPERTY(bool isAbstract READ isAbstract WRITE setAbstract)
    Q_PROPERTY(bool isFinalSpecialization READ isFinalSpecialization WRITE setFinalSpecialization)
    Q_PROPERTY(const QSet<QUseCase *> * ownedUseCases READ ownedUseCases)
    Q_PROPERTY(const QSet<QGeneralizationSet *> * powertypeExtents READ powertypeExtents)
    Q_PROPERTY(const QSet<QUseCase *> * useCases READ useCases)
    Q_PROPERTY(QClassifierTemplateParameter * templateParameter READ templateParameter WRITE setTemplateParameter)
    Q_PROPERTY(const QSet<QClassifier *> * redefinedClassifiers READ redefinedClassifiers)
    Q_PROPERTY(QRedefinableTemplateSignature * ownedTemplateSignature READ ownedTemplateSignature WRITE setOwnedTemplateSignature)
    Q_PROPERTY(const QSet<QCollaborationUse *> * collaborationUses READ collaborationUses)
    Q_PROPERTY(const QSet<QProperty *> * attributes READ attributes)
    Q_PROPERTY(const QSet<QFeature *> * features READ features)
    Q_PROPERTY(const QSet<QClassifier *> * generals READ generals)
    Q_PROPERTY(QCollaborationUse * representation READ representation WRITE setRepresentation)
    Q_PROPERTY(const QSet<QGeneralization *> * generalizations READ generalizations)
    Q_PROPERTY(const QSet<QNamedElement *> * inheritedMembers READ inheritedMembers)
    Q_PROPERTY(const QSet<QSubstitution *> * substitutions READ substitutions)

    // From aggregated QRelationship
    Q_PROPERTY(const QSet<QElement *> * relatedElements READ relatedElements)

    // From QAssociation
    Q_PROPERTY(bool isDerived READ isDerived WRITE setDerived)
    Q_PROPERTY(const QList<QType *> * endTypes READ endTypes)
    Q_PROPERTY(const QSet<QProperty *> * navigableOwnedEnds READ navigableOwnedEnds)
    Q_PROPERTY(const QList<QProperty *> * ownedEnds READ ownedEnds)
    Q_PROPERTY(const QList<QProperty *> * memberEnds READ memberEnds)

    Q_DISABLE_COPY(QAssociation)
    Q_DECLARE_PRIVATE(QAssociation)

public:
    explicit QAssociation(QObject *parent = 0);
    virtual ~QAssociation();

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
    bool isAbstract() const;
    void setAbstract(bool isAbstract);
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
    const QSet<QClassifier *> *generals() const;
    void addGeneral(QClassifier *general);
    void removeGeneral(QClassifier *general);
    QCollaborationUse *representation() const;
    void setRepresentation(QCollaborationUse *representation);
    const QSet<QGeneralization *> *generalizations() const;
    void addGeneralization(QGeneralization *generalization);
    void removeGeneralization(QGeneralization *generalization);
    const QSet<QNamedElement *> *inheritedMembers() const;
    const QSet<QSubstitution *> *substitutions() const;
    void addSubstitution(QSubstitution *substitution);
    void removeSubstitution(QSubstitution *substitution);

    // Association ends from aggregated QRelationship
    const QSet<QElement *> *relatedElements() const;

    // Attributes from QAssociation
    bool isDerived() const;
    void setDerived(bool isDerived);

    // Association ends from QAssociation
    const QList<QType *> *endTypes() const;
    const QSet<QProperty *> *navigableOwnedEnds() const;
    void addNavigableOwnedEnd(QProperty *navigableOwnedEnd);
    void removeNavigableOwnedEnd(QProperty *navigableOwnedEnd);
    const QList<QProperty *> *ownedEnds() const;
    void addOwnedEnd(QProperty *ownedEnd);
    void removeOwnedEnd(QProperty *ownedEnd);
    const QList<QProperty *> *memberEnds() const;
    void addMemberEnd(QProperty *memberEnd);
    void removeMemberEnd(QProperty *memberEnd);

protected:
    explicit QAssociation(QAssociationPrivate &dd, QObject *parent = 0);

private:
    QClassifier *_wrappedClassifier;
    QRelationship *_wrappedRelationship;
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QAssociation) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QAssociation) *> *)

QT_END_HEADER

#endif // QTUML_QASSOCIATION_H

