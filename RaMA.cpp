﻿/*
 * Copyright [2024] [MALABZ_UESTC Pinglu Zhang]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 // Author: Pinglu Zhang
 // Contact: pingluzhang@outlook.com
 // Created: 2024-01-29
#include "config.h"
#include "utils.h"
#include "logging.h"
#include "anchor.h"
#include "threadpool.h"
#include "pairwise_alignment.h"

Logger logger("/mnt/f/code/vs_code/RaMA/output/", "RaMA", true, info);


int main(int argc, char** argv) {
	std::ios::sync_with_stdio(false);
	
	const char* data_path = "/mnt/f/code/vs_code/RaMA/data/human.fasta";

	std::vector<SequenceInfo>* data = new std::vector<SequenceInfo>(readDataPath(data_path));
	AnchorFinder anchorfinder(*data, true,"/mnt/f/code/vs_code/RaMA/output/save/", false, true);
	RareMatchPairs final_anchors = anchorfinder.lanuchAnchorSearching();

	delete data;
	logger.info() << "Max memory used is " << logger.getMaxMemoryUsed() << std::endl;

	return 0;
}