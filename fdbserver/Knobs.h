/*
 * Knobs.h
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2018 Apple Inc. and the FoundationDB project authors
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

#ifndef FDBSERVER_KNOBS_H
#define FDBSERVER_KNOBS_H
#pragma once

#include "flow/Knobs.h"
#include "fdbrpc/fdbrpc.h"
#include "fdbclient/Knobs.h"

// Disk queue
static const int _PAGE_SIZE = 4096;

class ServerKnobs : public Knobs {
public:
	// TLogs
	double TLOG_TIMEOUT;  // tlog OR master proxy failure - master's reaction time
	double RECOVERY_TLOG_SMART_QUORUM_DELAY;		// smaller might be better for bug amplification
	double TLOG_STORAGE_MIN_UPDATE_INTERVAL;
	double BUGGIFY_TLOG_STORAGE_MIN_UPDATE_INTERVAL;
	double UNFLUSHED_DATA_RATIO;
	int DESIRED_TOTAL_BYTES;
	int MAXIMUM_PEEK_BYTES;
	int APPLY_MUTATION_BYTES;
	int RECOVERY_DATA_BYTE_LIMIT;
	int BUGGIFY_RECOVERY_DATA_LIMIT;
	double LONG_TLOG_COMMIT_TIME;
	int64_t LARGE_TLOG_COMMIT_BYTES;
	double BUGGIFY_RECOVER_MEMORY_LIMIT;
	double BUGGIFY_WORKER_REMOVED_MAX_LAG;
	int64_t UPDATE_STORAGE_BYTE_LIMIT;
	double TLOG_PEEK_DELAY;
	int LEGACY_TLOG_UPGRADE_ENTRIES_PER_VERSION;
	int VERSION_MESSAGES_OVERHEAD_FACTOR_1024THS; // Multiplicative factor to bound total space used to store a version message (measured in 1/1024ths, e.g. a value of 2048 yields a factor of 2).
	int64_t VERSION_MESSAGES_ENTRY_BYTES_WITH_OVERHEAD;
	double TLOG_MESSAGE_BLOCK_OVERHEAD_FACTOR;
	int64_t TLOG_MESSAGE_BLOCK_BYTES;
	int64_t MAX_MESSAGE_SIZE;
	int LOG_SYSTEM_PUSHED_DATA_BLOCK_SIZE;
	double PEEK_TRACKER_EXPIRATION_TIME;
	int PARALLEL_GET_MORE_REQUESTS;
	int64_t MAX_QUEUE_COMMIT_BYTES;

	// Versions
	int VERSIONS_PER_SECOND;
	int MAX_VERSIONS_IN_FLIGHT;
	int MAX_READ_TRANSACTION_LIFE_VERSIONS;
	int MAX_WRITE_TRANSACTION_LIFE_VERSIONS;
	double MAX_COMMIT_BATCH_INTERVAL; // Each master proxy generates a CommitTransactionBatchRequest at least this often, so that versions always advance smoothly

	// Data distribution queue
	double HEALTH_POLL_TIME;
	double BEST_TEAM_STUCK_DELAY;
	double BG_DD_POLLING_INTERVAL;
	double DD_QUEUE_LOGGING_INTERVAL;
	double RELOCATION_PARALLELISM_PER_SOURCE_SERVER;
	int DD_QUEUE_MAX_KEY_SERVERS;
	int DD_REBALANCE_PARALLELISM;
	int DD_REBALANCE_RESET_AMOUNT;
	double BG_DD_MAX_WAIT;
	double BG_DD_MIN_WAIT;
	double BG_DD_INCREASE_RATE;
	double BG_DD_DECREASE_RATE;
	double BG_DD_SATURATION_DELAY;
	double INFLIGHT_PENALTY_HEALTHY;
	double INFLIGHT_PENALTY_UNHEALTHY;
	double INFLIGHT_PENALTY_ONE_LEFT;

	// Data distribution
	double RETRY_RELOCATESHARD_DELAY;
	double DATA_DISTRIBUTION_FAILURE_REACTION_TIME;
	int MIN_SHARD_BYTES, SHARD_BYTES_RATIO, SHARD_BYTES_PER_SQRT_BYTES, MAX_SHARD_BYTES, KEY_SERVER_SHARD_BYTES;
	int64_t SHARD_MAX_BYTES_PER_KSEC, // Shards with more than this bandwidth will be split immediately
		SHARD_MIN_BYTES_PER_KSEC,     // Shards with more than this bandwidth will not be merged
		SHARD_SPLIT_BYTES_PER_KSEC;   // When splitting a shard, it is split into pieces with less than this bandwidth
	double STORAGE_METRIC_TIMEOUT;
	double METRIC_DELAY;
	double ALL_DATA_REMOVED_DELAY;
	double INITIAL_FAILURE_REACTION_DELAY;
	double CHECK_TEAM_DELAY;
	double LOG_ON_COMPLETION_DELAY;
	int BEST_TEAM_MAX_TEAM_TRIES;
	int BEST_TEAM_OPTION_COUNT;
	int BEST_OF_AMT;
	double SERVER_LIST_DELAY;
	double RECRUITMENT_IDLE_DELAY;
	double STORAGE_RECRUITMENT_DELAY;
	double DATA_DISTRIBUTION_LOGGING_INTERVAL;
	double DD_ENABLED_CHECK_DELAY;
	double DD_MERGE_COALESCE_DELAY;
	double STORAGE_METRICS_POLLING_DELAY;
	double STORAGE_METRICS_RANDOM_DELAY;
	double FREE_SPACE_RATIO_CUTOFF;
	double FREE_SPACE_RATIO_DD_CUTOFF;
	int DESIRED_TEAMS_PER_SERVER;
	int64_t DD_SHARD_SIZE_GRANULARITY;
	int64_t DD_SHARD_SIZE_GRANULARITY_SIM;
	int DD_MOVE_KEYS_PARALLELISM;
	int DD_MERGE_LIMIT;
	double DD_SHARD_METRICS_TIMEOUT;
	int64_t DD_LOCATION_CACHE_SIZE;
	double MOVEKEYS_LOCK_POLLING_DELAY;
	double DEBOUNCE_RECRUITING_DELAY;

	// KeyValueStore SQLITE
	int CLEAR_BUFFER_SIZE;
	double READ_VALUE_TIME_ESTIMATE;
	double READ_RANGE_TIME_ESTIMATE;
	double SET_TIME_ESTIMATE;
	double CLEAR_TIME_ESTIMATE;
	double COMMIT_TIME_ESTIMATE;
	int CHECK_FREE_PAGE_AMOUNT;
	double DISK_METRIC_LOGGING_INTERVAL;
	int64_t SOFT_HEAP_LIMIT;

	int SQLITE_PAGE_SCAN_ERROR_LIMIT;
	int SQLITE_BTREE_PAGE_USABLE;
	int SQLITE_BTREE_CELL_MAX_LOCAL;
	int SQLITE_BTREE_CELL_MIN_LOCAL;
	int SQLITE_FRAGMENT_PRIMARY_PAGE_USABLE;
	int SQLITE_FRAGMENT_OVERFLOW_PAGE_USABLE;
	double SQLITE_FRAGMENT_MIN_SAVINGS;

	// KeyValueStoreSqlite spring cleaning
	double CLEANING_INTERVAL;
	double SPRING_CLEANING_TIME_ESTIMATE;
	double SPRING_CLEANING_VACUUMS_PER_LAZY_DELETE_PAGE;
	int SPRING_CLEANING_MIN_LAZY_DELETE_PAGES;
	int SPRING_CLEANING_MAX_LAZY_DELETE_PAGES;
	int SPRING_CLEANING_LAZY_DELETE_BATCH_SIZE;
	int SPRING_CLEANING_MIN_VACUUM_PAGES;
	int SPRING_CLEANING_MAX_VACUUM_PAGES;

	// KeyValueStoreMemory
	int64_t REPLACE_CONTENTS_BYTES;

	// Leader election
	double CANDIDATE_MIN_DELAY;
	double CANDIDATE_MAX_DELAY;
	double CANDIDATE_GROWTH_RATE;
	double POLLING_FREQUENCY;
	double HEARTBEAT_FREQUENCY;

	// Master Proxy
	double START_TRANSACTION_BATCH_INTERVAL_MIN;
	double START_TRANSACTION_BATCH_INTERVAL_MAX;
	double START_TRANSACTION_BATCH_INTERVAL_LATENCY_FRACTION;
	double START_TRANSACTION_BATCH_INTERVAL_SMOOTHER_ALPHA;
	double START_TRANSACTION_BATCH_QUEUE_CHECK_INTERVAL;
	double START_TRANSACTION_MAX_TRANSACTIONS_TO_START;
	double START_TRANSACTION_MAX_BUDGET_SIZE;

	double COMMIT_TRANSACTION_BATCH_INTERVAL_FROM_IDLE;
	double COMMIT_TRANSACTION_BATCH_INTERVAL_MIN;
	double COMMIT_TRANSACTION_BATCH_INTERVAL_MAX;
	double COMMIT_TRANSACTION_BATCH_INTERVAL_LATENCY_FRACTION;
	double COMMIT_TRANSACTION_BATCH_INTERVAL_SMOOTHER_ALPHA;
	int    COMMIT_TRANSACTION_BATCH_COUNT_MAX;
	int    COMMIT_TRANSACTION_BATCH_BYTES_MIN;
	int    COMMIT_TRANSACTION_BATCH_BYTES_MAX;
	double COMMIT_TRANSACTION_BATCH_BYTES_SCALE_BASE;
	double COMMIT_TRANSACTION_BATCH_BYTES_SCALE_POWER;
	int64_t COMMIT_BATCHES_MEM_BYTES_HARD_LIMIT;
	double COMMIT_BATCHES_MEM_FRACTION_OF_TOTAL;
	double COMMIT_BATCHES_MEM_TO_TOTAL_MEM_SCALE_FACTOR;

	double TRANSACTION_BUDGET_TIME;
	double RESOLVER_COALESCE_TIME;
	int BUGGIFIED_ROW_LIMIT;
	double PROXY_SPIN_DELAY;

	// Master Server
	double MASTER_LOGGING_DELAY;
	double COMMIT_SLEEP_TIME;
	double MIN_BALANCE_TIME;
	int64_t MIN_BALANCE_DIFFERENCE;
	double SECONDS_BEFORE_NO_FAILURE_DELAY;
	int64_t MAX_TXS_SEND_MEMORY;
	int64_t MAX_RECOVERY_VERSIONS;
	double MAX_RECOVERY_TIME;

	// Resolver
	int64_t SAMPLE_OFFSET_PER_KEY;
	double SAMPLE_EXPIRATION_TIME;
	double SAMPLE_POLL_TIME;
	int64_t RESOLVER_STATE_MEMORY_LIMIT;

	//Cluster Controller
	double MASTER_FAILURE_REACTION_TIME;
	double MASTER_FAILURE_SLOPE_DURING_RECOVERY;
	int WORKER_COORDINATION_PING_DELAY;
	double SIM_SHUTDOWN_TIMEOUT;
	double SHUTDOWN_TIMEOUT;
	double MASTER_SPIN_DELAY;
	double CC_CHANGE_DELAY;
	double WAIT_FOR_GOOD_RECRUITMENT_DELAY;
	double ATTEMPT_RECRUITMENT_DELAY;
	double WORKER_FAILURE_TIME;
	double CHECK_BETTER_MASTER_INTERVAL;
	double INCOMPATIBLE_PEERS_LOGGING_INTERVAL;
	double VERSION_LAG_METRIC_INTERVAL;
	int64_t MAX_VERSION_DIFFERENCE;

	// Knobs used to select the best policy (via monte carlo)
	int POLICY_RATING_TESTS;	// number of tests per policy (in order to compare)
	int POLICY_GENERATIONS;		// number of policies to generate

	int EXPECTED_MASTER_FITNESS;
	int EXPECTED_TLOG_FITNESS;
	int EXPECTED_LOG_ROUTER_FITNESS;
	int EXPECTED_PROXY_FITNESS;
	int EXPECTED_RESOLVER_FITNESS;
	double RECRUITMENT_TIMEOUT;

	//Move Keys
	double SHARD_READY_DELAY;
	double SERVER_READY_QUORUM_INTERVAL;
	double SERVER_READY_QUORUM_TIMEOUT;
	double REMOVE_RETRY_DELAY;
	int MOVE_KEYS_KRM_LIMIT;
	int MOVE_KEYS_KRM_LIMIT_BYTES; //This must be sufficiently larger than CLIENT_KNOBS->KEY_SIZE_LIMIT (fdbclient/Knobs.h) to ensure that at least two entries will be returned from an attempt to read a key range map
	int MAX_SKIP_TAGS;

	//FdbServer
	double MIN_REBOOT_TIME;
	double MAX_REBOOT_TIME;
	std::string LOG_DIRECTORY;
	int64_t SERVER_MEM_LIMIT;

	//Ratekeeper
	double SMOOTHING_AMOUNT;
	double SLOW_SMOOTHING_AMOUNT;
	double METRIC_UPDATE_RATE;
	double LAST_LIMITED_RATIO;

	int64_t TARGET_BYTES_PER_STORAGE_SERVER;
	double SPRING_BYTES_STORAGE_SERVER;

	int64_t TARGET_BYTES_PER_TLOG;
	double SPRING_BYTES_TLOG;
	int64_t TLOG_SPILL_THRESHOLD;

	double MAX_TRANSACTIONS_PER_BYTE;

	int64_t MIN_FREE_SPACE;
	double MIN_FREE_SPACE_RATIO;

	double MAX_TL_SS_VERSION_DIFFERENCE; // spring starts at half this value
	int MAX_MACHINES_FALLING_BEHIND;

	//Storage Metrics
	double STORAGE_METRICS_AVERAGE_INTERVAL;
	double STORAGE_METRICS_AVERAGE_INTERVAL_PER_KSECONDS;
	double SPLIT_JITTER_AMOUNT;
	int64_t IOPS_UNITS_PER_SAMPLE;
	int64_t BANDWIDTH_UNITS_PER_SAMPLE;

	//Storage Server
	double STORAGE_LOGGING_DELAY;
	double STORAGE_SERVER_POLL_METRICS_DELAY;
	double FUTURE_VERSION_DELAY;
	int STORAGE_LIMIT_BYTES;
	int BUGGIFY_LIMIT_BYTES;
	int FETCH_BLOCK_BYTES;
	int FETCH_KEYS_PARALLELISM_BYTES;
	int BUGGIFY_BLOCK_BYTES;
	int64_t STORAGE_HARD_LIMIT_BYTES;
	int STORAGE_COMMIT_BYTES;
	double STORAGE_COMMIT_INTERVAL;
	double UPDATE_SHARD_VERSION_INTERVAL;
	int BYTE_SAMPLING_FACTOR;
	int BYTE_SAMPLING_OVERHEAD;
	int MAX_STORAGE_SERVER_WATCH_BYTES;
	int MAX_BYTE_SAMPLE_CLEAR_MAP_SIZE;
	double LONG_BYTE_SAMPLE_RECOVERY_DELAY;

	//Wait Failure
	int BUGGIFY_OUTSTANDING_WAIT_FAILURE_REQUESTS;
	int MAX_OUTSTANDING_WAIT_FAILURE_REQUESTS;
	double WAIT_FAILURE_DELAY_LIMIT;

	//Worker
	double WORKER_LOGGING_INTERVAL;
	double INCOMPATIBLE_PEER_DELAY_BEFORE_LOGGING;

	// Test harness
	double WORKER_POLL_DELAY;

	// Coordination
	double COORDINATED_STATE_ONCONFLICT_POLL_INTERVAL;

	// Buggification
	double BUGGIFIED_EVENTUAL_CONSISTENCY;
	bool BUGGIFY_ALL_COORDINATION;

	// Status
	double STATUS_MIN_TIME_BETWEEN_REQUESTS;
	int CONFIGURATION_ROWS_TO_FETCH;

	// Timekeeper
	int64_t TIME_KEEPER_DELAY;
	int64_t TIME_KEEPER_MAX_ENTRIES;

	ServerKnobs(bool randomize = false, ClientKnobs* clientKnobs = NULL);
};

extern ServerKnobs const* SERVER_KNOBS;

#endif
