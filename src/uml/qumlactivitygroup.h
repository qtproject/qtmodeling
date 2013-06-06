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
#ifndef QUMLACTIVITYGROUP_H
#define QUMLACTIVITYGROUP_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QUmlNamedElement>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

// Forward decls for function parameters
class QUmlActivityGroup;
class QUmlActivity;
class QUmlActivityEdge;
class QUmlActivityNode;

class QUmlActivityGroupPrivate;

class Q_UML_EXPORT QUmlActivityGroup : public QUmlNamedElement
{
    Q_OBJECT
    Q_CLASSINFO("MetaModelPrefix", "QUml")

    Q_PROPERTY(QUmlActivity * inActivity READ inActivity WRITE setInActivity)
    Q_PROPERTY(QSet<QUmlActivityNode *> containedNodes READ containedNodes)
    Q_PROPERTY(QSet<QUmlActivityGroup *> subgroups READ subgroups)
    Q_PROPERTY(QSet<QUmlActivityEdge *> containedEdges READ containedEdges)
    Q_PROPERTY(QUmlActivityGroup * superGroup READ superGroup)

    Q_DISABLE_COPY(QUmlActivityGroup)
    Q_DECLARE_PRIVATE(QUmlActivityGroup)

public:
    Q_INVOKABLE explicit QUmlActivityGroup(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QUmlActivityGroup();

    // Association ends from QUmlActivityGroup
    Q_INVOKABLE QUmlActivity *inActivity() const;
    Q_INVOKABLE void setInActivity(QUmlActivity *inActivity);
    Q_INVOKABLE QSet<QUmlActivityNode *> containedNodes() const;
    Q_INVOKABLE QSet<QUmlActivityGroup *> subgroups() const;
    Q_INVOKABLE QSet<QUmlActivityEdge *> containedEdges() const;
    Q_INVOKABLE QUmlActivityGroup *superGroup() const;

    virtual void setPropertyData();

    // Classes which access read-only opposite properties should be friend
    friend class QUmlActivityEdgePrivate;
    friend class QUmlActivityNodePrivate;

protected:
    explicit QUmlActivityGroup(QUmlActivityGroupPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLACTIVITYGROUP_H
