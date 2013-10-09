/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtModeling module of the Qt Toolkit.
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
#ifndef QTMODELING_QXMIREADER_P_H
#define QTMODELING_QXMIREADER_P_H

#include "qtmodelingglobal.h"
#include "private/qobject_p.h"

#include <QtCore/QStringList>
#include <QtCore/QXmlStreamReader>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtModeling)

class QMetaModelPlugin;
class QScriptEngine;

class Q_MODELING_EXPORT QXmiReaderPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QXmiReader)

public:
    explicit QXmiReaderPrivate();
    virtual ~QXmiReaderPrivate();

    QHash<QString, QModelingObject *> idMap;
    QHash< QString, QPair<QMetaModelPlugin *, QJsonObject> > metaModelPlugins;
    QHash<QString, QString> xmlNamespaceToImplementationNamespace;
    QStringList errors;
    QScriptEngine *scriptEngine;
    bool initMetaModel;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTMODELING_QXMIREADER_P_H
