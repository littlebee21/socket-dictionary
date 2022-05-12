
DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user`(
	Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	name TEXT,
	password TEXT,
	loginStatus INTEGER
);

INSERT INTO `user` VALUES ('1', 'gao', '123','0');
INSERT INTO `user` VALUES ('2', 'wang', '456','0');





DROP TABLE IF EXISTS `searchHistory`;
CREATE TABLE IF NOT EXISTS `searchHistory`(
        Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        name TEXT,
        searchWord TEXT,
        time TEXT,
        searchResult INTEGER
);
INSERT INTO `searchHistory` VALUES ('1', 'gao','abandon' ,'2022-0512-14','0');
