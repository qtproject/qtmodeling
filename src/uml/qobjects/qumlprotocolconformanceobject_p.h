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
#ifndef QUMLPROTOCOLCONFORMANCEOBJECT_H
#define QUMLPROTOCOLCONFORMANCEOBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtModeling/QModelingObject>

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlProtocolConformance;
class QModelingObjectPrivate;
class Q_UML_EXPORT QUmlProtocolConformanceObject : public QModelingObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QUmlProtocolConformanceObject)
    Q_DECLARE_PRIVATE(QModelingObject)

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComments READ ownedComments NOTIFY ownedCommentsChanged)
    Q_PROPERTY(QSet<QObject *> ownedElements READ ownedElements NOTIFY ownedElementsChanged)
    Q_PROPERTY(QObject * owner READ owner NOTIFY ownerChanged)

    // Properties [Relationship]
    Q_PROPERTY(QSet<QObject *> relatedElements READ relatedElements NOTIFY relatedElementsChanged)

    // Properties [DirectedRelationship]
    Q_PROPERTY(QSet<QObject *> sources READ sources NOTIFY sourcesChanged)
    Q_PROPERTY(QSet<QObject *> targets READ targets NOTIFY targetsChanged)

    // Properties [ProtocolConformance]
    Q_PROPERTY(QObject * generalMachine READ generalMachine WRITE setGeneralMachine NOTIFY generalMachineChanged)
    Q_PROPERTY(QObject * specificMachine READ specificMachine WRITE setSpecificMachine NOTIFY specificMachineChanged)

public:
    Q_INVOKABLE explicit QUmlProtocolConformanceObject(QUmlProtocolConformance *modelingElement);

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [Relationship]
    Q_INVOKABLE const QSet<QObject *> relatedElements() const;

    // Owned attributes [DirectedRelationship]
    Q_INVOKABLE const QSet<QObject *> sources() const;
    Q_INVOKABLE const QSet<QObject *> targets() const;

    // Owned attributes [ProtocolConformance]
    Q_INVOKABLE QObject *generalMachine() const;
    Q_INVOKABLE QObject *specificMachine() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [Relationship]
    void Q_DECL_HIDDEN addRelatedElement(QObject *relatedElement);
    void Q_DECL_HIDDEN removeRelatedElement(QObject *relatedElement);

    // Slots for owned attributes [DirectedRelationship]
    void Q_DECL_HIDDEN addSource(QObject *source);
    void Q_DECL_HIDDEN removeSource(QObject *source);
    void Q_DECL_HIDDEN addTarget(QObject *target);
    void Q_DECL_HIDDEN removeTarget(QObject *target);

    // Slots for owned attributes [ProtocolConformance]
    void setGeneralMachine(QObject *generalMachine = 0);
    void setSpecificMachine(QObject *specificMachine = 0);

Q_SIGNALS:

    // Signals for owned attributes [Element]
    void ownedCommentsChanged(QSet<QObject *> ownedComments);
    void ownedElementsChanged(QSet<QObject *> ownedElements);
    void ownerChanged(QObject *owner);

    // Signals for owned attributes [Relationship]
    void relatedElementsChanged(QSet<QObject *> relatedElements);

    // Signals for owned attributes [DirectedRelationship]
    void sourcesChanged(QSet<QObject *> sources);
    void targetsChanged(QSet<QObject *> targets);

    // Signals for owned attributes [ProtocolConformance]
    void generalMachineChanged(QObject *generalMachine);
    void specificMachineChanged(QObject *specificMachine);

protected:
    virtual void setGroupProperties();
    virtual void setPropertyData();
};

QT_END_NAMESPACE

#endif // QUMLPROTOCOLCONFORMANCEOBJECT_H

