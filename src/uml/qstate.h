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
#ifndef QTUML_QSTATE_H
#define QTUML_QSTATE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for aggregated 'base classes'
class QNamespace;
class QRedefinableElement;
class QVertex;

// Forward decls for function parameters
class QStateMachine;
class QClassifier;
class QConstraint;
class QRegion;
class QBehavior;
class QConnectionPointReference;
class QTrigger;
class QPseudostate;

class QStatePrivate;

class Q_UML_EXPORT QState : public QObject
{
    Q_OBJECT

    // From QState
    Q_PROPERTY(bool isSimple READ isSimple)
    Q_PROPERTY(bool isComposite READ isComposite)
    Q_PROPERTY(bool isOrthogonal READ isOrthogonal)
    Q_PROPERTY(bool isSubmachineState READ isSubmachineState)
    Q_PROPERTY(const QSet<QRegion *> * regions READ regions)
    Q_PROPERTY(QBehavior * exit READ exit WRITE setExit)
    Q_PROPERTY(const QSet<QConnectionPointReference *> * connections READ connections)
    Q_PROPERTY(QClassifier * redefinitionContext READ redefinitionContext)
    Q_PROPERTY(QState * redefinedState READ redefinedState WRITE setRedefinedState)
    Q_PROPERTY(const QSet<QTrigger *> * deferrableTriggers READ deferrableTriggers)
    Q_PROPERTY(const QSet<QPseudostate *> * connectionPoints READ connectionPoints)
    Q_PROPERTY(QBehavior * entry READ entry WRITE setEntry)
    Q_PROPERTY(QBehavior * doActivity READ doActivity WRITE setDoActivity)
    Q_PROPERTY(QStateMachine * submachine READ submachine WRITE setSubmachine)
    Q_PROPERTY(QConstraint * stateInvariant READ stateInvariant WRITE setStateInvariant)

    // From aggregated QElement
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)

    // From aggregated QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
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

    // From aggregated QRedefinableElement
    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf)
    Q_PROPERTY(const QSet<QRedefinableElement *> * redefinedElements READ redefinedElements)

    // From aggregated QVertex
    Q_PROPERTY(const QSet<QTransition *> * incomings READ incomings)
    Q_PROPERTY(QRegion * container READ container WRITE setContainer)
    Q_PROPERTY(const QSet<QTransition *> * outgoings READ outgoings)

    Q_DISABLE_COPY(QState)
    Q_DECLARE_PRIVATE(QState)

public:
    explicit QState(QObject *parent = 0);
    virtual ~QState();

    // Attributes
    bool isSimple() const;
    bool isComposite() const;
    bool isOrthogonal() const;
    bool isSubmachineState() const;

    // Association-ends
    const QSet<QRegion *> *regions() const;
    void addRegion(QRegion *region);
    void removeRegion(QRegion *region);
    QBehavior *exit() const;
    void setExit(QBehavior *exit);
    const QSet<QConnectionPointReference *> *connections() const;
    void addConnection(QConnectionPointReference *connection);
    void removeConnection(QConnectionPointReference *connection);
    QClassifier *redefinitionContext() const;
    QState *redefinedState() const;
    void setRedefinedState(QState *redefinedState);
    const QSet<QTrigger *> *deferrableTriggers() const;
    void addDeferrableTrigger(QTrigger *deferrableTrigger);
    void removeDeferrableTrigger(QTrigger *deferrableTrigger);
    const QSet<QPseudostate *> *connectionPoints() const;
    void addConnectionPoint(QPseudostate *connectionPoint);
    void removeConnectionPoint(QPseudostate *connectionPoint);
    QBehavior *entry() const;
    void setEntry(QBehavior *entry);
    QBehavior *doActivity() const;
    void setDoActivity(QBehavior *doActivity);
    QStateMachine *submachine() const;
    void setSubmachine(QStateMachine *submachine);
    QConstraint *stateInvariant() const;
    void setStateInvariant(QConstraint *stateInvariant);

    // Operations
    QStateMachine *containingStateMachine() const;
    bool isConsistentWith(const QRedefinableElement *redefinee) const;
    bool isRedefinitionContextValid(const QState *redefined) const;

protected:
    explicit QState(QStatePrivate &dd, QObject *parent = 0);

private:
    QNamespace *_wrappedNamespace;
    QRedefinableElement *_wrappedRedefinableElement;
    QVertex *_wrappedVertex;
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QState) *)
Q_DECLARE_METATYPE(QSet<QT_PREPEND_NAMESPACE_QTUML(QState) *> *)
Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QState) *> *)

QT_END_HEADER

#endif // QTUML_QSTATE_H

