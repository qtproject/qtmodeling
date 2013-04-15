/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the [% namespace.split('/').0 %] module of the Qt Toolkit.
**
** \$QT_BEGIN_LICENSE:LGPL\$
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
** \$QT_END_LICENSE\$
**
****************************************************************************/
#ifndef ${class.name.upper}_P_H
#define ${class.name.upper}_P_H

// Base class includes
[%- IF !class.superclass || class.superclass.size > 1 -%]

#include "private/qwrappedobject_p.h"
[%- END -%]
[%- FOREACH superclass IN class.superclass -%]

#include "private/${superclass.name.lower}_p.h"
[%- END %]

#include "${namespace}/${class.name}"
[%- IF class.item('qtumlinclude') %]

// [% namespace.split('/').0 %] includes
[%- FOREACH include IN class.qtumlinclude -%]

#include "${include}"
[%- END -%]
[%- END -%]
[%- IF class.item('qtinclude') %]

// Qt includes
[%- FOREACH include IN class.qtinclude -%]

#include "${include}"
[%- END -%]
[%- END %]

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE([% namespace.split('/').0 %])

[%- found = 'false' -%]
[%- foundPublic = 'false' -%]
[%- FOREACH forwarddecl IN class.forwarddecl -%]
[%- IF forwarddecl.namespace == namespace.replace('/', '::') -%]
[%- IF found == 'false' -%]

// Forward decls for function parameters
[% found = 'true' -%]
[%- END -%]
class ${forwarddecl.class};

[%- IF forwarddecl.content == class.name -%]
[%- foundPublic = 'true' -%]
[%- END -%]
[%- END -%]
[%- END -%]
[% IF class.isAbstract == 'false' and foundPublic == 'false' -%]
class ${class.name};

[%- END %]
class Q_[% namespace.split('/').0.substr(2).upper %]_EXPORT ${class.name}Private : [% IF class.superclass.size == 1 %]public ${class.superclass.0.name.split('/').last}Private[% ELSE %]public QWrappedObjectPrivate[% END %]
{
    Q_DECLARE_PUBLIC(${class.name})

public:
    explicit ${class.name}Private();
    virtual ~${class.name}Private();

[%- FOREACH attribute IN class.attribute.values %]
[%- IF (attribute.isDerived == 'false' or attribute.isDerivedUnion == 'true') %]
    ${attribute.accessor.0.return.remove('^const ').remove('&$')}${attribute.accessor.0.name};
[%- END -%]
[%- END -%]
[%- FOREACH associationend IN class.associationend.values %]
[%- IF (associationend.isDerived == 'false' or associationend.isDerivedUnion == 'true') %]
    ${associationend.accessor.0.return.remove('^const ').remove('&$')}${associationend.accessor.0.name};
[%- END -%]
[%- END -%]
[%- IF class.item('attribute') -%]
[%- found = 'false' -%]
[%- FOREACH attribute IN class.attribute.values -%]
[%- IF attribute.isReadOnly == 'true' and attribute.subsettedBy != '' -%]
[%- IF found == 'false' -%]
[%- found = 'true' %]

    // Internal functions for read-only subsetted attributes
[%- END -%]
[%- FOREACH accessor IN attribute.accessor -%]
[%- NEXT IF loop.first %]
    ${accessor.return}${accessor.name}([%- FOREACH parameter IN accessor.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END
 -%])${accessor.constness};
[%- END -%]
[%- END -%]
[%- END -%]
[%- END %]
[%- IF class.item('associationend') %]
[%- found = 'false' -%]
[%- FOREACH associationend IN class.associationend.values -%]
[%- IF associationend.isReadOnly == 'true' and (associationend.subsettedBy != '' or associationend.oppositeEnd != '') -%]
[%- IF found == 'false' -%]
[%- found = 'true' %]

    // Internal functions for read-only subsetted association ends
[%- END -%]
[%- FOREACH accessor IN associationend.accessor -%]
[%- NEXT IF loop.first %]
    ${accessor.return}${accessor.name}([%- FOREACH parameter IN accessor.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END
 -%])${accessor.constness};
[%- END -%]
[%- END -%]
[%- END -%]
[%- END %]
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // ${class.name.upper}_P_H

