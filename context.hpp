namespace Persistency
{
	template< class Implementation >
	class Context
	{
		public:
			bool commit();

		private:
			Implementation * get_implementation()
			{
				return static_cast< Implementation * >( this );
			}
	};
}

template< class Implementation >
bool Persistency::Context< Implementation >::commit()
{
	return get_implementation() -> _commit();
}
