#pragma once

#include "TopologyFactory.h"

namespace Topologic
{
	namespace Factories
	{
		/// <summary>
		/// (private) A private factory class to create a CellComplex.
		/// </summary>
		ref class CellComplexFactory : TopologyFactory
		{
		public:
			/// <summary>
			/// Creates a CellComplex from a TopologicCore layer Topology.
			/// </summary>
			/// <param name="kpTopology">A TopologicCore layer Topology</param>
			/// <returns name="Topology">The created CellComplex</returns>
#ifdef TOPOLOGIC_DYNAMO
			[IsVisibleInDynamoLibrary(false)]
#endif
			virtual Topology^ Create(const TopologicCore::TopologyPtr& kpTopology) override;
		};
	}
}