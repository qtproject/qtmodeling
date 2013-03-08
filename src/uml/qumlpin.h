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
#ifndef QUMLPIN_H
#define QUMLPIN_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
#include <QtUml/QUmlMultiplicityElement>
#include <QtUml/QUmlObjectNode>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlPinPrivate;

class Q_UML_EXPORT QUmlPin : public QWrappedObject
{
    Q_OBJECT

    Q_PROPERTY(QSet<QUmlElement *> ownedElements READ ownedElements)
    Q_PROPERTY(QUmlElement * owner READ owner)
    Q_PROPERTY(QSet<QUmlComment *> ownedComments READ ownedComments)

    Q_PROPERTY(qint32 upper READ upper WRITE setUpper RESET unsetUpper STORED false)
    Q_PROPERTY(bool isUnique READ isUnique WRITE setUnique RESET unsetUnique)
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setOrdered RESET unsetOrdered)
    Q_PROPERTY(qint32 lower READ lower WRITE setLower STORED false)
    Q_PROPERTY(QUmlValueSpecification * upperValue READ upperValue WRITE setUpperValue)
    Q_PROPERTY(QUmlValueSpecification * lowerValue READ lowerValue WRITE setLowerValue)

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QUmlStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QUmlNamespace * namespace_ READ namespace_)
    Q_PROPERTY(QSet<QUmlDependency *> clientDependencies READ clientDependencies)

    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf RESET unsetLeaf)
    Q_PROPERTY(QSet<QUmlRedefinableElement *> redefinedElements READ redefinedElements)
    Q_PROPERTY(QSet<QUmlClassifier *> redefinitionContexts READ redefinitionContexts)

    Q_PROPERTY(QSet<QUmlActivityNode *> redefinedNodes READ redefinedNodes)
    Q_PROPERTY(QSet<QUmlActivityEdge *> incomings READ incomings)
    Q_PROPERTY(QUmlActivity * activity READ activity WRITE setActivity)
    Q_PROPERTY(QSet<QUmlActivityGroup *> inGroup READ inGroup)
    Q_PROPERTY(QUmlStructuredActivityNode * inStructuredNode READ inStructuredNode WRITE setInStructuredNode)
    Q_PROPERTY(QSet<QUmlActivityPartition *> inPartition READ inPartition)
    Q_PROPERTY(QSet<QUmlInterruptibleActivityRegion *> inInterruptibleRegion READ inInterruptibleRegion)
    Q_PROPERTY(QSet<QUmlActivityEdge *> outgoings READ outgoings)

    Q_PROPERTY(QUmlType * type READ type WRITE setType)

    Q_PROPERTY(bool isControlType READ isControlType WRITE setControlType RESET unsetControlType)
    Q_PROPERTY(QtUml::ObjectNodeOrderingKind ordering READ ordering WRITE setOrdering RESET unsetOrdering)
    Q_PROPERTY(QUmlValueSpecification * upperBound READ upperBound WRITE setUpperBound)
    Q_PROPERTY(QUmlBehavior * selection READ selection WRITE setSelection)
    Q_PROPERTY(QSet<QUmlState *> inState READ inState)

    Q_PROPERTY(bool isControl READ isControl WRITE setControl RESET unsetControl)

    Q_DISABLE_COPY(QUmlPin)
    Q_DECLARE_PRIVATE(QUmlPin)

public:
    Q_INVOKABLE explicit QUmlPin(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QUmlPin();

    // Association ends from aggregated QUmlElement
    Q_INVOKABLE QSet<QUmlElement *> ownedElements() const;
    Q_INVOKABLE QUmlElement *owner() const;
    Q_INVOKABLE QSet<QUmlComment *> ownedComments() const;
    Q_INVOKABLE void addOwnedComment(QUmlComment *ownedComment);
    Q_INVOKABLE void removeOwnedComment(QUmlComment *ownedComment);

    // Attributes from aggregated QUmlMultiplicityElement
    Q_INVOKABLE qint32 upper() const;
    Q_INVOKABLE void setUpper(qint32 upper);
    Q_INVOKABLE void unsetUpper();
    Q_INVOKABLE bool isUnique() const;
    Q_INVOKABLE void setUnique(bool isUnique);
    Q_INVOKABLE void unsetUnique();
    Q_INVOKABLE bool isOrdered() const;
    Q_INVOKABLE void setOrdered(bool isOrdered);
    Q_INVOKABLE void unsetOrdered();
    Q_INVOKABLE qint32 lower() const;
    Q_INVOKABLE void setLower(qint32 lower);

    // Association ends from aggregated QUmlMultiplicityElement
    Q_INVOKABLE QUmlValueSpecification *upperValue() const;
    Q_INVOKABLE void setUpperValue(QUmlValueSpecification *upperValue);
    Q_INVOKABLE QUmlValueSpecification *lowerValue() const;
    Q_INVOKABLE void setLowerValue(QUmlValueSpecification *lowerValue);

    // Attributes from aggregated QUmlNamedElement
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setName(QString name);
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;
    Q_INVOKABLE void setVisibility(QtUml::VisibilityKind visibility);
    Q_INVOKABLE QString qualifiedName() const;

    // Association ends from aggregated QUmlNamedElement
    Q_INVOKABLE QUmlStringExpression *nameExpression() const;
    Q_INVOKABLE void setNameExpression(QUmlStringExpression *nameExpression);
    Q_INVOKABLE QUmlNamespace *namespace_() const;
    Q_INVOKABLE QSet<QUmlDependency *> clientDependencies() const;
    Q_INVOKABLE void addClientDependency(QUmlDependency *clientDependency);
    Q_INVOKABLE void removeClientDependency(QUmlDependency *clientDependency);

    // Attributes from aggregated QUmlRedefinableElement
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE void setLeaf(bool isLeaf);
    Q_INVOKABLE void unsetLeaf();

    // Association ends from aggregated QUmlRedefinableElement
    Q_INVOKABLE QSet<QUmlRedefinableElement *> redefinedElements() const;
    Q_INVOKABLE QSet<QUmlClassifier *> redefinitionContexts() const;

    // Association ends from aggregated QUmlActivityNode
    Q_INVOKABLE QSet<QUmlActivityNode *> redefinedNodes() const;
    Q_INVOKABLE void addRedefinedNode(QUmlActivityNode *redefinedNode);
    Q_INVOKABLE void removeRedefinedNode(QUmlActivityNode *redefinedNode);
    Q_INVOKABLE QSet<QUmlActivityEdge *> incomings() const;
    Q_INVOKABLE void addIncoming(QUmlActivityEdge *incoming);
    Q_INVOKABLE void removeIncoming(QUmlActivityEdge *incoming);
    Q_INVOKABLE QUmlActivity *activity() const;
    Q_INVOKABLE void setActivity(QUmlActivity *activity);
    Q_INVOKABLE QSet<QUmlActivityGroup *> inGroup() const;
    Q_INVOKABLE QUmlStructuredActivityNode *inStructuredNode() const;
    Q_INVOKABLE void setInStructuredNode(QUmlStructuredActivityNode *inStructuredNode);
    Q_INVOKABLE QSet<QUmlActivityPartition *> inPartition() const;
    Q_INVOKABLE void addInPartition(QUmlActivityPartition *inPartition);
    Q_INVOKABLE void removeInPartition(QUmlActivityPartition *inPartition);
    Q_INVOKABLE QSet<QUmlInterruptibleActivityRegion *> inInterruptibleRegion() const;
    Q_INVOKABLE void addInInterruptibleRegion(QUmlInterruptibleActivityRegion *inInterruptibleRegion);
    Q_INVOKABLE void removeInInterruptibleRegion(QUmlInterruptibleActivityRegion *inInterruptibleRegion);
    Q_INVOKABLE QSet<QUmlActivityEdge *> outgoings() const;
    Q_INVOKABLE void addOutgoing(QUmlActivityEdge *outgoing);
    Q_INVOKABLE void removeOutgoing(QUmlActivityEdge *outgoing);

    // Association ends from aggregated QUmlTypedElement
    Q_INVOKABLE QUmlType *type() const;
    Q_INVOKABLE void setType(QUmlType *type);

    // Attributes from aggregated QUmlObjectNode
    Q_INVOKABLE bool isControlType() const;
    Q_INVOKABLE void setControlType(bool isControlType);
    Q_INVOKABLE void unsetControlType();
    Q_INVOKABLE QtUml::ObjectNodeOrderingKind ordering() const;
    Q_INVOKABLE void setOrdering(QtUml::ObjectNodeOrderingKind ordering);
    Q_INVOKABLE void unsetOrdering();

    // Association ends from aggregated QUmlObjectNode
    Q_INVOKABLE QUmlValueSpecification *upperBound() const;
    Q_INVOKABLE void setUpperBound(QUmlValueSpecification *upperBound);
    Q_INVOKABLE QUmlBehavior *selection() const;
    Q_INVOKABLE void setSelection(QUmlBehavior *selection);
    Q_INVOKABLE QSet<QUmlState *> inState() const;
    Q_INVOKABLE void addInState(QUmlState *inState);
    Q_INVOKABLE void removeInState(QUmlState *inState);

    // Attributes from QUmlPin
    Q_INVOKABLE bool isControl() const;
    Q_INVOKABLE void setControl(bool isControl);
    Q_INVOKABLE void unsetControl();

    virtual void setPropertyData();

protected:
    explicit QUmlPin(QUmlPinPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);

private:
    QUmlMultiplicityElement *_wrappedUmlMultiplicityElement;
    QUmlObjectNode *_wrappedUmlObjectNode;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLPIN_H

