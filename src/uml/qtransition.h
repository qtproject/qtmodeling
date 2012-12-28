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
#ifndef QTUML_QTRANSITION_H
#define QTUML_QTRANSITION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
using QtWrappedObjects::QWrappedObject;
#include <QtUml/QRedefinableElement>
#include <QtUml/QNamespace>

// QtUml includes
#include <QtUml/QtUmlEnumerations>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QTrigger;
class QVertex;
class QStateMachine;
class QClassifier;
class QRegion;
class QConstraint;
class QBehavior;

class QTransitionPrivate;

class Q_UML_EXPORT QTransition : public QWrappedObject
{
    Q_OBJECT

    Q_PROPERTY(QtUml::TransitionKind kind READ kind WRITE setKind RESET unsetKind)
    Q_PROPERTY(QConstraint * guard READ guard WRITE setGuard)
    Q_PROPERTY(QVertex * target READ target WRITE setTarget)
    Q_PROPERTY(QBehavior * effect READ effect WRITE setEffect)
    Q_PROPERTY(QRegion * container READ container WRITE setContainer)
    Q_PROPERTY(QClassifier * redefinitionContext READ redefinitionContext STORED false)
    Q_PROPERTY(QTransition * redefinedTransition READ redefinedTransition WRITE setRedefinedTransition)
    Q_PROPERTY(QVertex * source READ source WRITE setSource)
    Q_PROPERTY(QSet<QTrigger *> triggers READ triggers)

    Q_DISABLE_COPY(QTransition)
    Q_DECLARE_PRIVATE(QTransition)

public:
    Q_INVOKABLE explicit QTransition(QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
    virtual ~QTransition();

    // Association ends from aggregated QElement
    Q_INVOKABLE const QSet<QElement *> &ownedElements() const;
    Q_INVOKABLE QElement *owner() const;
    Q_INVOKABLE const QSet<QComment *> &ownedComments() const;
    Q_INVOKABLE void addOwnedComment(QComment *ownedComment);
    Q_INVOKABLE void removeOwnedComment(QComment *ownedComment);

    // Attributes from aggregated QNamedElement
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setName(QString name);
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;
    Q_INVOKABLE void setVisibility(QtUml::VisibilityKind visibility);
    Q_INVOKABLE QString qualifiedName() const;

    // Association ends from aggregated QNamedElement
    Q_INVOKABLE QStringExpression *nameExpression() const;
    Q_INVOKABLE void setNameExpression(QStringExpression *nameExpression);
    Q_INVOKABLE QNamespace *namespace_() const;
    Q_INVOKABLE const QSet<QDependency *> &clientDependencies() const;
    Q_INVOKABLE void addClientDependency(QDependency *clientDependency);
    Q_INVOKABLE void removeClientDependency(QDependency *clientDependency);

    // Attributes from aggregated QRedefinableElement
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE void setLeaf(bool isLeaf);
    Q_INVOKABLE void unsetLeaf();

    // Association ends from aggregated QRedefinableElement
    Q_INVOKABLE const QSet<QRedefinableElement *> &redefinedElements() const;

    // Association ends from aggregated QNamespace
    Q_INVOKABLE const QSet<QPackageImport *> &packageImports() const;
    Q_INVOKABLE void addPackageImport(QPackageImport *packageImport);
    Q_INVOKABLE void removePackageImport(QPackageImport *packageImport);
    Q_INVOKABLE const QSet<QNamedElement *> &members() const;
    Q_INVOKABLE const QSet<QPackageableElement *> &importedMembers() const;
    Q_INVOKABLE const QSet<QElementImport *> &elementImports() const;
    Q_INVOKABLE void addElementImport(QElementImport *elementImport);
    Q_INVOKABLE void removeElementImport(QElementImport *elementImport);
    Q_INVOKABLE const QSet<QConstraint *> &ownedRules() const;
    Q_INVOKABLE void addOwnedRule(QConstraint *ownedRule);
    Q_INVOKABLE void removeOwnedRule(QConstraint *ownedRule);
    Q_INVOKABLE const QSet<QNamedElement *> &ownedMembers() const;

    // Attributes from QTransition
    Q_INVOKABLE QtUml::TransitionKind kind() const;
    Q_INVOKABLE void setKind(QtUml::TransitionKind kind);
    Q_INVOKABLE void unsetKind();

    // Association ends from QTransition
    Q_INVOKABLE QConstraint *guard() const;
    Q_INVOKABLE void setGuard(QConstraint *guard);
    Q_INVOKABLE QVertex *target() const;
    Q_INVOKABLE void setTarget(QVertex *target);
    Q_INVOKABLE QBehavior *effect() const;
    Q_INVOKABLE void setEffect(QBehavior *effect);
    Q_INVOKABLE QRegion *container() const;
    Q_INVOKABLE void setContainer(QRegion *container);
    Q_INVOKABLE QClassifier *redefinitionContext() const;
    Q_INVOKABLE QTransition *redefinedTransition() const;
    Q_INVOKABLE void setRedefinedTransition(QTransition *redefinedTransition);
    Q_INVOKABLE QVertex *source() const;
    Q_INVOKABLE void setSource(QVertex *source);
    Q_INVOKABLE const QSet<QTrigger *> &triggers() const;
    Q_INVOKABLE void addTrigger(QTrigger *trigger);
    Q_INVOKABLE void removeTrigger(QTrigger *trigger);

    // Operations
    Q_INVOKABLE QStateMachine *containingStateMachine() const;
    Q_INVOKABLE bool isConsistentWith(const QRedefinableElement *redefinee) const;

protected:
    explicit QTransition(QTransitionPrivate &dd, QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);

private:
    QRedefinableElement *_wrappedRedefinableElement;
    QNamespace *_wrappedNamespace;
};

QT_END_NAMESPACE_QTUML

QT_END_HEADER

#endif // QTUML_QTRANSITION_H

