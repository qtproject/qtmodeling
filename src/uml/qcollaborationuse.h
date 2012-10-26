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
#ifndef QTUML_QCOLLABORATIONUSE_H
#define QTUML_QCOLLABORATIONUSE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QNamedElement>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QDependency;
class QCollaboration;

class Q_UML_EXPORT QCollaborationUse : public QObject, public QNamedElement
{
    Q_OBJECT

    // From QElement
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)

    // From QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(const QSet<QDependency *> * clientDependencies READ clientDependencies)

    // From QCollaborationUse
    Q_PROPERTY(QCollaboration * type READ type WRITE setType)
    Q_PROPERTY(const QSet<QDependency *> * roleBindings READ roleBindings)

    Q_DISABLE_COPY(QCollaborationUse)

public:
    explicit QCollaborationUse(QObject *parent = 0);
    virtual ~QCollaborationUse();

    // Association-ends
    QCollaboration *type() const;
    void setType(QCollaboration *type);
    const QSet<QDependency *> *roleBindings() const;
    void addRoleBinding(QDependency *roleBinding);
    void removeRoleBinding(QDependency *roleBinding);

protected:
    explicit QCollaborationUse(bool createPimpl, QObject *parent = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QCollaborationUse) *>)
Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QCollaborationUse) *> *)

QT_END_HEADER

#endif // QTUML_QCOLLABORATIONUSE_H
