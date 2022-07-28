/*
 Navicat Premium Data Transfer

 Source Server         : kshoppingcentre
 Source Server Type    : SQLite
 Source Server Version : 3030001
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001

 Date: 07/06/2022 20:41:45
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS "user";
CREATE TABLE "user" (
  "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "username" TEXT NOT NULL,
  "password" TEXT NOT NULL
);

-- ----------------------------
-- Records of user
-- ----------------------------
BEGIN;
INSERT INTO "user" VALUES (1, '123', '1234');
INSERT INTO "user" VALUES (2, 'Gates', 'Beijing');
INSERT INTO "user" VALUES (4, '1234', '1234');
INSERT INTO "user" VALUES (6, 'java', 'cpp');
INSERT INTO "user" VALUES (7, '12345', '1234');
INSERT INTO "user" VALUES (8, 'abcd', 'abcd');
INSERT INTO "user" VALUES (9, 'hello1', 'world');
INSERT INTO "user" VALUES (10, '1235', '123');
COMMIT;

-- ----------------------------
-- Auto increment value for user
-- ----------------------------
UPDATE "main"."sqlite_sequence" SET seq = 10 WHERE name = 'user';

-- ----------------------------
-- Indexes structure for table user
-- ----------------------------
CREATE UNIQUE INDEX "main"."unique_username"
ON "user" (
  "username" COLLATE BINARY ASC
);

PRAGMA foreign_keys = true;
