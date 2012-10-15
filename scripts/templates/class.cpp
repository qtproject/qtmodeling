[%- MACRO HANDLESUBSETTEDPROPERTY(property, operation, singlevalued) BLOCK -%]
    [%- IF property.subsettedProperty != '' %]
    [%- found = 'false' -%]
    [%- FOREACH subsettedProperty IN property.subsettedProperty.split(' ') -%]
        [%- subsettedClass = subsettedProperty.split('-').0.replace('^', 'Q') -%]
        [%- IF classes.item(subsettedClass).attribute.item(subsettedProperty) -%]
        [%- subsettedPropertyItem = classes.item(subsettedClass).attribute.item(subsettedProperty) -%]
        [%- ELSE -%]
        [%- subsettedPropertyItem = classes.item(subsettedClass).associationend.item(subsettedProperty) -%]
        [%- END -%]
        [%- IF operation == 1 and subsettedPropertyItem.accessor.1 -%]
            [%- IF found == 'false' %]

        // Adjust subsetted property(ies)
            [%- found = 'true' -%]
            [%- END %]
            [%- IF property.isReadOnly == subsettedPropertyItem.isReadOnly %]
        ${subsettedPropertyItem.accessor.1.name}(${accessor.parameter.0.name});
            [%- ELSIF property.isReadOnly == 'false' and subsettedPropertyItem.isReadOnly == 'true' %]
        d->${subsettedPropertyItem.accessor.1.name}(${accessor.parameter.0.name});
            [%- ELSE %]
        QTUML_Q(${class.name});
        q->${subsettedPropertyItem.accessor.1.name}(${accessor.parameter.0.name});
            [%- END %]
        [%- ELSE -%][%- IF operation == 2 and subsettedPropertyItem.accessor.2 -%]
            [%- IF found == 'false' -%]
            [%- IF singlevalued == 'false' %]

            [%- END %]
        // Adjust subsetted property(ies)
            [%- found = 'true' -%]
            [%- END %]
            [%- IF property.isReadOnly == 'true' and subsettedPropertyItem.isReadOnly == 'true' %]
        ${subsettedPropertyItem.accessor.2.name}([% IF singlevalued == 'true' %]this->[% END %]${accessor.parameter.0.name});
            [%- ELSIF property.isReadOnly == 'false' and subsettedPropertyItem.isReadOnly == 'false' %]
        ${subsettedPropertyItem.accessor.2.name}([% IF singlevalued == 'true' %]d->[% END %]${accessor.parameter.0.name});
            [%- ELSIF property.isReadOnly == 'false' and subsettedPropertyItem.isReadOnly == 'true' %]
        d->${subsettedPropertyItem.accessor.2.name}([% IF singlevalued == 'true' %]d->[% END %]${accessor.parameter.0.name});
            [%- ELSE %]
        QTUML_Q(${class.name});
        q->${subsettedPropertyItem.accessor.2.name}([% IF singlevalued == 'true' %]this->[% END %]${accessor.parameter.0.name});
            [%- END %]
        [%- END -%]
        [%- END -%]
    [%- END -%]
    [%- IF found == 'true' and operation == 2 and singlevalued == 'true' %]

    [%- END -%]
    [%- END -%]
[%- END -%]
[%- MACRO HANDLEOPPOSITEEND(property, accessor, operation) BLOCK -%]
[%- IF property.oppositeEnd != '' -%]
[%- opposite = classes.item(property.oppositeEnd.split('-').0.replace('^', 'Q')).associationend.item(property.oppositeEnd) %]

        // Adjust opposite property
        [%- IF property.isReadOnly == 'true' %]
        QTUML_Q(${class.name});
        [%- END %]
    [%- IF operation == 1 %]
        [%- IF opposite.isReadOnly == 'false' %]
        ${accessor.parameter.0.name}->${opposite.accessor.1.name}([% IF property.isReadOnly == 'true' %]q[% ELSE %]this[% END %]);
        [%- ELSE %]
        (dynamic_cast<${accessor.parameter.0.type.replace(' \*$', '').replace('$', 'Private *')}>(${accessor.parameter.0.name}->d_umlptr))->${opposite.accessor.1.name}([% IF property.isReadOnly == 'true' %]q[% ELSE %]this[% END %]);
        [%- END %]
    [%- ELSE -%][%- IF operation == 2 and opposite.accessor.size > 2 %]
        [%- IF opposite.isReadOnly == 'false' %]
        ${accessor.parameter.0.name}->${opposite.accessor.2.name}([% IF property.isReadOnly == 'true' %]q[% ELSE %]this[% END %]);
        [%- ELSE %]
        (dynamic_cast<${accessor.parameter.0.type.replace(' \*$', '').replace('$', 'Private *')}>(${accessor.parameter.0.name}->d_umlptr))->${opposite.accessor.2.name}([% IF property.isReadOnly == 'true' %]q[% ELSE %]this[% END %]);
        [%- END %]
    [%- ELSE %]
        [%- IF opposite.isReadOnly == 'false' %]
        ${accessor.parameter.0.name}->${opposite.accessor.1.name}(0);
        [%- ELSE %]
        (dynamic_cast<${accessor.parameter.0.type.replace(' \*$', '').replace('$', 'Private *')}>(${accessor.parameter.0.name}->d_umlptr))->${opposite.accessor.1.name}(0);
        [%- END %]
    [%- END -%][%- END -%]
[%- END -%]
[%- END -%]
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
** rights. These rights are described in the Nokia Qt LGPL Exception
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

#include "${class.name.lower}.h"
#include "${class.name.lower}_p.h"

[%- oppositeReadOnlyClasses = [] -%]
[%- FOREACH associationend IN class.associationend.values -%]
[%- oppositeClass = associationend.oppositeEnd.split('-').0.replace('^', 'Q') -%]
[%- IF classes.item(oppositeClass).associationend.item(associationend.oppositeEnd).isReadOnly == 'true' and oppositeClass != class.name -%]
[%- oppositeReadOnlyClasses.push(oppositeClass.lower.replace('$', '_p.h')) -%]
[%- END -%]
[%- END -%]
[%- FOREACH oppositeReadOnlyClass IN oppositeReadOnlyClasses.unique -%]
#include "${oppositeReadOnlyClass}"

[%- END %]
[%- FOREACH forwarddecl IN class.forwarddecl -%]
[%- IF forwarddecl.content != class.name -%]

#include <${forwarddecl.namespace}/${forwarddecl.content}>
[%- END -%]
[%- END %]

QT_BEGIN_NAMESPACE_${namespace.replace('/', '_').upper}

${class.name}Private::${class.name}Private([%- IF class.isAbstract == 'false' -%]${class.name} *q_umlptr[%- END -%])
[%- found = 'false' -%]
[%- FOREACH attribute IN class.attribute.values %]
[%- IF attribute.isDerived == 'false' or attribute.isDerivedUnion == 'true' -%]
[%- IF attribute.accessor.0.return.search('<') -%]
[%- IF found == 'true' -%]
,
[% ELSE -%]
 :
    [%- found = 'true' %]
[% END -%]
    ${attribute.accessor.0.name}(new ${attribute.accessor.0.return.remove(' \*$').remove('^const ')})
[%- ELSE -%]
[%- IF attribute.accessor.0.return.search('\*') -%]
[%- IF found == 'true' -%]
,
[% ELSE -%]
 :
    [%- found = 'true' %]
[% END -%]
    ${attribute.accessor.0.name}(0)
[%- ELSE -%]
[%- IF attribute.defaultValue != '' -%]
[%- IF found == 'true' -%]
,
[% ELSE -%]
 :
    [%- found = 'true' %]
[% END -%]
    ${attribute.accessor.0.name}(${attribute.defaultValue})
[%- END -%]
[%- END -%]
[%- END -%]
[%- END -%]
[%- END -%]
[%- FOREACH associationend IN class.associationend.values %]
[%- IF associationend.isDerived == 'false' or associationend.isDerivedUnion == 'true' -%]
[%- IF associationend.accessor.0.return.search('<') -%]
[%- IF found == 'true' -%]
,
[% ELSE -%]
 :
    [%- found = 'true' %]
[% END -%]
    ${associationend.accessor.0.name}(new ${associationend.accessor.0.return.remove(' \*$').remove('^const ')})
[%- ELSE -%]
[%- IF associationend.accessor.0.return.search('\*') -%]
[%- IF found == 'true' -%]
,
[% ELSE -%]
 :
    [%- found = 'true' %]
[% END -%]
    ${associationend.accessor.0.name}(0)
[%- ELSE -%]
[%- IF associationend.defaultValue != '' -%]
[%- IF found == 'true' -%]
,
[% ELSE -%]
 :
    [%- found = 'true' %]
[% END -%]
    ${associationend.accessor.0.name}(${associationend.defaultValue})
[%- END -%]
[%- END -%]
[%- END -%]
[%- END -%]
[%- END %]
{
    [%- IF class.isAbstract == 'false' %]
    this->q_umlptr = q_umlptr;
    [%- END %]
}

${class.name}Private::~${class.name}Private()
{
[% FOREACH attribute IN class.attribute.values -%]
[%- IF attribute.aggregation == 'composite' and attribute.accessor.0.return.search('<') and attribute.subsettedProperty == '' -%]
    foreach (${attribute.accessor.1.parameter.0.type.remove('^const ')}${attribute.accessor.1.parameter.0.type.remove('^Q').remove('\*').trim.lower}, *${attribute.accessor.0.name})
        delete ${attribute.accessor.1.parameter.0.type.remove('^Q').remove('\*').trim.lower};

[%- END -%]
[%- IF ((attribute.isDerived == 'false' or attribute.isDerivedUnion == 'true') and attribute.accessor.0.return.search('<')) or (attribute.accessor.0.return.search('\*$') and attribute.aggregation == 'composite' and attribute.subsettedProperty == '') -%]
    delete ${attribute.accessor.0.name};

[%- END -%]
[%- END -%]
[%- FOREACH associationend IN class.associationend.values -%]
[%- IF associationend.aggregation == 'composite' and associationend.accessor.0.return.search('<') and associationend.subsettedProperty == '' -%]
    foreach (${associationend.accessor.1.parameter.0.type.remove('^const ')}${associationend.accessor.1.parameter.0.type.remove('^Q').remove('\*').trim.lower}, *${associationend.accessor.0.name})
        delete ${associationend.accessor.1.parameter.0.type.remove('^Q').remove('\*').trim.lower};

[%- END -%]
[%- IF ((associationend.isDerived == 'false' or associationend.isDerivedUnion == 'true') and associationend.accessor.0.return.search('<')) or (associationend.accessor.0.return.search('\*$') and associationend.aggregation == 'composite' and associationend.subsettedProperty == '') -%]
    delete ${associationend.accessor.0.name};

[%- END -%]
[%- END -%]
}

[%- FOREACH attribute IN class.attribute.values -%]
[%- IF attribute.isReadOnly == 'true' and attribute.subsettedBy != '' -%]
[%- FOREACH accessor IN attribute.accessor -%]
[%- NEXT IF loop.first %]
${accessor.return}${class.name}Private::${accessor.name}([%- FOREACH parameter IN accessor.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END -%])${accessor.constness}
{
    // This is a read-only [% IF attribute.isDerivedUnion == 'true' %]derived-union [% ELSE %][% IF attribute.isDerived == 'true' %]derived [% END %][% END %]attribute

[%- IF attribute.isDerived == 'false' or attribute.isDerivedUnion == 'true' %]
    [%- IF attribute.accessor.0.return.search('<') %]
    if ([% IF loop.count == 2 %]![% END %]this->${attribute.accessor.0.name}->contains(${accessor.parameter.0.name})) {
    [%- ELSE %]
    if (this->${attribute.accessor.0.name} != ${accessor.parameter.0.name}) {
    [%- END %]
    [%- IF accessor.name.search('^set') %]
    [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'true') %]
        this->${accessor.parameter.0.name} = ${accessor.parameter.0.name};
    [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'true') -%]
    [%- END -%]
    [%- IF accessor.name.search('^add') %]
        this->${attribute.accessor.0.name}->[% IF attribute.accessor.0.return.search('QSet') %]insert[% ELSE %]append[% END %](${accessor.parameter.0.name});
    [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'false') -%]
    [%- END -%]
    [%- IF accessor.name.search('^remove') %]
        this->${attribute.accessor.0.name}->[% IF attribute.accessor.0.return.search('QSet') %]remove[% ELSE %]removeAll[% END %](${accessor.parameter.0.name});
    [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'false') -%]
    [%- END -%]
    }
[%- ELSE %]
    qWarning("${class.name}::${accessor.name}: to be implemented (this is a derived attribute)");

    [%- IF attribute.accessor.0.return.search('<') %]
    if (false /* <derived-[% IF loop.count == 2 %]inclusion[% ELSE %]exclusion[% END %]-criteria> */) {
    [%- ELSE %]
    if (false /* <derived-change-criteria> */) {
    [%- END %]
    [%- IF accessor.name.search('^set') %]
    [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'true') %]
        // <derived-code>
    [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'true') -%]
    [%- END -%]
    [%- IF accessor.name.search('^add') %]
        // <derived-code>
    [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'false') -%]
    [%- END -%]
    [%- IF accessor.name.search('^remove') %]
        // <derived-code>
    [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'false') -%]
    [%- END -%]
    }
[%- END %]
}
[% END -%]
[%- END -%]
[%- END -%]

[%- FOREACH associationend IN class.associationend.values %]
[%- IF associationend.isReadOnly == 'true' and (associationend.subsettedBy != '' or associationend.oppositeEnd != '') -%]
[%- FOREACH accessor IN associationend.accessor -%]
[%- NEXT IF loop.first %]
${accessor.return}${class.name}Private::${accessor.name}([%- FOREACH parameter IN accessor.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END -%])${accessor.constness}
{
    // This is a read-only [% IF associationend.isDerivedUnion == 'true' %]derived-union [% ELSE %][% IF associationend.isDerived == 'true' %]derived [% END %][% END %]association end

[%- IF associationend.isDerived == 'false' or associationend.isDerivedUnion == 'true' %]
    [%- IF associationend.accessor.0.return.search('<') %]
    if ([% IF loop.count == 2 %]![% END %]this->${associationend.accessor.0.name}->contains(${accessor.parameter.0.name})) {
    [%- ELSE %]
    if (this->${associationend.accessor.0.name} != ${accessor.parameter.0.name}) {
    [%- END %]
    [%- IF accessor.name.search('^set') %]
    [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'true') %]
        this->${accessor.parameter.0.name} = ${accessor.parameter.0.name};
    [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'true') -%]
    [%- END -%]
    [%- IF accessor.name.search('^add') %]
        this->${associationend.accessor.0.name}->[% IF associationend.accessor.0.return.search('QSet') %]insert[% ELSE %]append[% END %](${accessor.parameter.0.name});
    [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'false') -%]
    [%- END -%]
    [%- IF accessor.name.search('^remove') %]
        this->${associationend.accessor.0.name}->[% IF associationend.accessor.0.return.search('QSet') %]remove[% ELSE %]removeAll[% END %](${accessor.parameter.0.name});
    [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'false') -%]
    [%- END -%]
    [%- HANDLEOPPOSITEEND(associationend, accessor, loop.count - 1) %]
    }
[%- ELSE %]
    qWarning("${class.name}::${accessor.name}: to be implemented (this is a derived associationend)");

    [%- IF associationend.accessor.0.return.search('<') %]
    if (false /* <derived[% IF loop.count == 2 %]inclusion[% ELSE %]exclusion[% END %]-criteria> */) {
    [%- ELSE %]
    if (false /* <derived-change-criteria> */) {
    [%- END %]
    [%- IF accessor.name.search('^set') %]
    [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'true') %]
        // <derived-code>
    [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'true') -%]
    [%- END -%]
    [%- IF accessor.name.search('^add') %]
        // <derived-code>
    [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'false') -%]
    [%- END -%]
    [%- IF accessor.name.search('^remove') %]
        // <derived-code>
    [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'false') -%]
    [%- END -%]
    [%- HANDLEOPPOSITEEND(associationend, accessor, loop.count - 1) %]
    }
[%- END %]
}
[% END -%]
[%- END -%]
[%- END -%]

[%- IF class.documentation %]
/*!
    \class ${class.name}

    \inmodule QtUml

    \brief ${class.documentation}
 */
[%- END %]

${class.name}::${class.name}([%- IF class.isAbstract == 'false' -%]QObject *parent[%- END -%])
[%- IF class.isAbstract == 'false' %]
[% GET '    : ' -%]
[% IF class.superobject -%]${class.superobject.split('/').last}(false, parent)[%- ELSE -%]QObject(parent)[%- END -%]
[%- END %]
{
[%- IF class.isAbstract == 'false' %]
    d_umlptr = new ${class.name}Private(this);
[%- END %]
}
[%- IF class.isAbstract == 'false' %]

${class.name}::${class.name}(bool createPimpl, QObject *parent)
[% GET '    : ' -%]
[% IF class.superobject -%]${class.superobject.split('/').last}(createPimpl, parent)[%- ELSE -%]QObject(parent)[%- END %]
{
    if (createPimpl)
        d_umlptr = new ${class.name}Private;
}
[%- END %]

${class.name}::~${class.name}()
{
[%- IF not(class.superclass) %]
    delete d_umlptr;
[%- END %]
}

[%- FOREACH attribute IN class.attribute.values %]
[%- IF (attribute.documentation) %]
/*!
    [% attribute.documentation %]
 */
[%- END %]
[%- FOREACH accessor IN attribute.accessor %]
${accessor.return}${class.name}::${accessor.name}([%- FOREACH parameter IN accessor.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END -%])${accessor.constness}
{
    // This is a [% IF attribute.isReadOnly == 'true' %]read-only [% ELSE %]read-write [% END %][% IF attribute.isDerivedUnion == 'true' %]derived-union [% ELSE %][% IF attribute.isDerived == 'true' %]derived [% END %][% END %]attribute

[%- IF attribute.isDerived == 'false' or attribute.isDerivedUnion == 'true' %]
    [%- IF loop.first %]
    QTUML_D(const ${class.name});
    return d->${accessor.name};
    [%- ELSE %]
    QTUML_D(${class.name});
    [%- IF attribute.accessor.0.return.search('<') %]
    if ([% IF loop.count == 2 %]![% END %]d->${attribute.accessor.0.name}->contains(${accessor.parameter.0.name})) {
    [%- ELSE %]
    if (d->${attribute.accessor.0.name} != ${accessor.parameter.0.name}) {
    [%- END %]
        [%- IF attribute.isReadOnly == 'true' %]
        d->${accessor.name}(${accessor.parameter.0.name});
        [%- ELSE -%]
            [%- IF accessor.name.search('^set') %]
            [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'true') %]
        d->${accessor.parameter.0.name} = ${accessor.parameter.0.name};
            [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'true') -%]
            [%- END -%]
            [%- IF accessor.name.search('^add') %]
        d->${attribute.accessor.0.name}->[% IF attribute.accessor.0.return.search('QSet') %]insert[% ELSE %]append[% END %](${accessor.parameter.0.name});
            [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'false') -%]
    [%- END -%]
            [%- IF accessor.name.search('^remove') %]
        d->${attribute.accessor.0.name}->[% IF attribute.accessor.0.return.search('QSet') %]remove[% ELSE %]removeAll[% END %](${accessor.parameter.0.name});
            [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'false') -%]
            [%- END -%]
        [%- END %]
    }
    [%- END -%]
[%- ELSE %]
    qWarning("${class.name}::${accessor.name}: to be implemented (this is a derived attribute)");

    [%- IF loop.first %]
    //QTUML_D(const ${class.name});
    //return <derived-return>;
    [%- ELSE %]
    //QTUML_D(${class.name});
    [%- IF attribute.accessor.0.return.search('<') %]
    if (false /* <derived-[% IF loop.count == 2 %]inclusion[% ELSE %]exclusion[% END %]-criteria> */) {
    [%- ELSE %]
    if (false /* <derived-change-criteria> */) {
    [%- END %]
        [%- IF attribute.isReadOnly == 'true' %]
        // <derived-code>
        [%- ELSE -%]
            [%- IF accessor.name.search('^set') %]
            [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'true') %]
        // <derived-code>
            [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'true') -%]
            [%- END -%]
            [%- IF accessor.name.search('^add') %]
        // <derived-code>
            [%- HANDLESUBSETTEDPROPERTY(attribute, 1, 'false') -%]
    [%- END -%]
            [%- IF accessor.name.search('^remove') %]
        // <derived-code>
            [%- HANDLESUBSETTEDPROPERTY(attribute, 2, 'false') -%]
            [%- END -%]
        [%- END %]
    }
    [%- END -%]
[%- END %]
}
[% LAST IF attribute.isReadOnly == 'true' -%]
[% END -%]
[%- END -%]

[%- FOREACH associationend IN class.associationend.values %]
[%- IF (associationend.documentation) %]
/*!
    [% associationend.documentation %]
 */
[%- END %]
[%- FOREACH accessor IN associationend.accessor %]
${accessor.return}${class.name}::${accessor.name}([%- FOREACH parameter IN accessor.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END -%])${accessor.constness}
{
    // This is a [% IF associationend.isReadOnly == 'true' %]read-only [% ELSE %]read-write [% END %][% IF associationend.isDerivedUnion == 'true' %]derived-union [% ELSE %][% IF associationend.isDerived == 'true' %]derived [% END %][% END %]association end

[%- IF associationend.isDerived == 'false' or associationend.isDerivedUnion == 'true' %]
    [%- IF loop.first %]
    QTUML_D(const ${class.name});
    return d->${accessor.name};
    [%- ELSE %]
    QTUML_D(${class.name});
    [%- IF associationend.accessor.0.return.search('<') %]
    if ([% IF loop.count == 2 %]![% END %]d->${associationend.accessor.0.name}->contains(${accessor.parameter.0.name})) {
    [%- ELSE %]
    if (d->${associationend.accessor.0.name} != ${accessor.parameter.0.name}) {
    [%- END %]
        [%- IF associationend.isReadOnly == 'true' %]
        d->${accessor.name}(${accessor.parameter.0.name});
        [%- ELSE -%]
            [%- IF accessor.name.search('^set') %]
            [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'true') %]
        d->${accessor.parameter.0.name} = ${accessor.parameter.0.name};
            [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'true') -%]
            [%- END -%]
            [%- IF accessor.name.search('^add') %]
        d->${associationend.accessor.0.name}->[% IF associationend.accessor.0.return.search('QSet') %]insert[% ELSE %]append[% END %](${accessor.parameter.0.name});
            [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'false') -%]
            [%- END -%]
            [%- IF accessor.name.search('^remove') %]
        d->${associationend.accessor.0.name}->[% IF associationend.accessor.0.return.search('QSet') %]remove[% ELSE %]removeAll[% END %](${accessor.parameter.0.name});
            [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'false') -%]
            [%- END -%]
        [%- END %]
    [%- END %]
[%- ELSE %]
    qWarning("${class.name}::${accessor.name}: to be implemented (this is a derived associationend)");

    [%- IF loop.first %]
    //QTUML_D(const ${class.name});
    //return <derived-return>;
    [%- ELSE %]
    //QTUML_D(${class.name});
    [%- IF associationend.accessor.0.return.search('<') %]
    if (false /* <derived-[% IF loop.count == 2 %]inclusion[% ELSE %]exclusion[% END %]-criteria> */) {
    [%- ELSE %]
    if (false /* <derived-change-criteria */) {
    [%- END %]
        [%- IF associationend.isReadOnly == 'true' %]
        // <derived-code>
        [%- ELSE -%]
            [%- IF accessor.name.search('^set') %]
            [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'true') %]
        // <derived-code>
            [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'true') -%]
            [%- END -%]
            [%- IF accessor.name.search('^add') %]
        // <derived-code>
            [%- HANDLESUBSETTEDPROPERTY(associationend, 1, 'false') -%]
            [%- END -%]
            [%- IF accessor.name.search('^remove') %]
        // <derived-code>
            [%- HANDLESUBSETTEDPROPERTY(associationend, 2, 'false') -%]
            [%- END -%]
        [%- END %]
    [%- END %]
[%- END %]
    [%- IF !loop.first %]
    [%- HANDLEOPPOSITEEND(associationend, accessor, loop.count - 1) %]
    }
    [%- END %]
}
[% LAST IF associationend.isReadOnly == 'true' -%]
[% END -%]
[%- END -%]

[%- FOREACH operation IN class.operation %]
[%- IF (operation.documentation) %]
/*!
    [% operation.documentation %]
 */
[%- END %]
${operation.return}${class.name}::${operation.name}([%- FOREACH parameter IN operation.parameter -%]${parameter.type}${parameter.name}[% IF !loop.last %], [% END %][%- END -%])${operation.constness}
{
    qWarning("${class.name}::${operation.name}: operation to be implemented");
}
[% END -%]
[%- IF class.isAbstract == 'false' %]
#include "moc_${class.name.lower}.cpp"
[% END %]
QT_END_NAMESPACE_${namespace.replace('/', '_').upper}

