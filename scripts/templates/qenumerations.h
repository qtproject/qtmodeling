/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** [% GET '$QT_BEGIN_LICENSE:LGPL$' %]
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
** [% GET '$QT_END_LICENSE$' %]
**
****************************************************************************/
#ifndef ${namespace.replace('/', '_').upper}_QENUMERATIONS_H
#define ${namespace.replace('/', '_').upper}_QENUMERATIONS_H

#include <QtUml/QtUmlGlobal>

#include <QtCore/QObject>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_${namespace.replace('/', '_').upper}

QT_MODULE(QtUml)

class Q_UML_EXPORT QEnumerations : public QObject
{
    Q_OBJECT

[% FOREACH enumeration IN enumerations -%]
    Q_ENUMS(${enumeration.name})
[% END %]
public:
[% FOREACH enumeration IN enumerations -%]
    enum ${enumeration.name}
    {
        [%- FOREACH literal IN enumeration.literal %]
        ${literal.name}[%- IF loop.first -%] = 0[%- END -%][%- IF !loop.last -%],[%- END -%]
        [%- END %]
    };
[% END -%]
private:
    explicit QEnumerations();
};

QT_END_NAMESPACE_${namespace.replace('/', '_').upper}

[%- FOREACH enumeration IN enumerations %]
Q_DECLARE_METATYPE(${namespace.replace('/', '::')}::QEnumerations::${enumeration.name})
[%- END %]

QT_END_HEADER

#endif // ${namespace.replace('/', '_').upper}_QENUMERATIONS_H
