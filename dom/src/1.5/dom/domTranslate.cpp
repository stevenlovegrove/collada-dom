#include <dae.h>
#include <dae/daeDom.h>
#include <dom/domTranslate.h>
#include <dae/daeMetaCMPolicy.h>
#include <dae/daeMetaSequence.h>
#include <dae/daeMetaChoice.h>
#include <dae/daeMetaGroup.h>
#include <dae/daeMetaAny.h>
#include <dae/daeMetaElementAttribute.h>

daeElementRef
domTranslate::create(DAE& dae)
{
	domTranslateRef ref = new domTranslate(dae);
	return ref;
}


daeMetaElement *
domTranslate::registerElement(DAE& dae)
{
	daeMetaElement* meta = dae.getMeta(ID());
	if ( meta != NULL ) return meta;

	meta = new daeMetaElement(dae);
	dae.setMeta(ID(), *meta);
	meta->setName( "translate" );
	meta->registerClass(domTranslate::create);

	//	Add attribute: _value
	{
		daeMetaAttribute *ma = new daeMetaAttribute;
		ma->setName( "_value" );
		ma->setType( dae.getAtomicTypes().get("Targetable_float3"));
		ma->setOffset( daeOffsetOf( domTranslate , _value ));
		ma->setContainer( meta );
		meta->appendAttribute(ma);
	}

	meta->setElementSize(sizeof(domTranslate));
	meta->validate();

	return meta;
}

