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
#ifndef QTUML_QTESTIDENTITYACTION_H
#define QTUML_QTESTIDENTITYACTION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QAction>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QInputPin;
class QOutputPin;

class QTestIdentityActionPrivate;

class Q_UML_EXPORT QTestIdentityAction : public QAction
{
    Q_OBJECT

    Q_PROPERTY(QInputPin * second READ second WRITE setSecond)
    Q_PROPERTY(QOutputPin * result READ result WRITE setResult)
    Q_PROPERTY(QInputPin * first READ first WRITE setFirst)

    Q_DISABLE_COPY(QTestIdentityAction)
    Q_DECLARE_PRIVATE(QTestIdentityAction)

public:
    Q_INVOKABLE explicit QTestIdentityAction(QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
    virtual ~QTestIdentityAction();

    // Association ends from QTestIdentityAction
    Q_INVOKABLE QInputPin *second() const;
    Q_INVOKABLE void setSecond(QInputPin *second);
    Q_INVOKABLE QOutputPin *result() const;
    Q_INVOKABLE void setResult(QOutputPin *result);
    Q_INVOKABLE QInputPin *first() const;
    Q_INVOKABLE void setFirst(QInputPin *first);
    virtual void registerMetaTypes() const;

protected:
    explicit QTestIdentityAction(QTestIdentityActionPrivate &dd, QWrappedObject *parent = 0, QWrappedObject *wrapper = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QTestIdentityAction) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QTestIdentityAction) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QTestIdentityAction) *> *)

QT_END_HEADER

#endif // QTUML_QTESTIDENTITYACTION_H

