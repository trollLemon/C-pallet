/* *
 * k_mean.h
 *
 * Header for an implementation of the K_Means clustering algorithm
 * for color palette generation.
 *
 * This header includes definitions for funcitons to perform the algorithm,
 * along with wrappers and custom comparators to help with the execution
 *
 *
 *
 * */

#ifndef KMEAN
#define KMEAN
#include "adv_color.h"
#include "cluster.h"
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include "util.h"
class KMean {

private:
  std::map<ADV_Color *, minHeap *>
      data; // Distances from points to each centroid
  std::unordered_map<int /*Cluster ID*/, Cluster *> clusters; // clusters
  std::vector<ADV_Color *> colors;

  /* *
   * inits the process for K_Means.
   *
   * K points are selected to create our initial clusters.
   *
   * */
  void K_MEAN_INIT(int k);

  /* *
   * Performs the Clustering.
   * Once the method is finished, the remaining centroids will
   * be our color palette
   *
   * */
  void K_MEAN_START();

  /* *
   * Returns the Euclidian Distance between two colors by looking
   * at the colors' LAB values
   * Assumes the Colors had their RGB values converted to LAB values
   * */
  double EuclidianDistance(ADV_Color *a, ADV_Color *b);

  /* *
   * Recalculates centroids for all clusters in the given set
   * This will be called in K_MEAN_START every iteration if Clusters gain or
   * lose points.
   * */
  void reCalculateCentroids(std::set<Cluster *>);

public:
  /* *
   * returns a vector of strings for each color in the palette.
   * They are represented as hex color codes (#FFFFFF) for ease of use
   * in config files, CSS, etc...
   * */
  std::vector<std::string> makePalette(std::vector<ADV_Color *> &colors, int k);
};

#endif
