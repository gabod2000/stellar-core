#ifndef __NODE__
#define __NODE__

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the ISC License. See the COPYING file at the top-level directory of
// this distribution or at http://opensource.org/licenses/ISC

#include <memory>
#include <vector>

#include "fba/FBA.h"

namespace stellar
{
/**
 * This is one Node in the stellar network
 */
class Node : public enable_shared_from_this<Node>
{
  public:
    Node(const uint256& nodeID);

    const FBAQuorumSet& retrieveQuorumSet(const uint256& qSetHash);
    void cacheQuorumSet(const uint256& qSetHash,
                        const FBAQuorumSet& qSet);
  private:
    uint256                         mNodeID;
    std::map<uint256, FBAQuorumSet> mCachedQuorumSets;
};
}

#endif
